#include "singletonclient.h"

SingletonClient* SingletonClient::p_instance = nullptr;
SingletonDestroyer SingletonClient::destroyer;

SingletonClient::SingletonClient(QObject* parent) : QObject(parent)
{
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket->connectToHost("127.0.0.1", 33333);

    connect(mTcpSocket, SIGNAL(readyRead()),
            this, SLOT(slotServerRead()));
}


SingletonClient* SingletonClient::getInstance()
{
    if (!p_instance)
    {
        p_instance = new SingletonClient();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

QByteArray SingletonClient::encryptData(const QString& data)
{
    unsigned char key[16] = "123456789012345";
    AES aes(key);
    QByteArray encryptedText = aes.encrypt(data);
    return encryptedText;
}

QString SingletonClient::decryptData(const QByteArray& encryptedData)
{
    unsigned char key[16] = "123456789012345";
    AES aes(key);
    QString decrypted = aes.decrypt(encryptedData);
    return decrypted;
}

QString SingletonClient::send_msg_to_server(QString query)
{
    QByteArray encryptedData = encryptData(query);
    mTcpSocket->write(encryptedData);
    mTcpSocket->waitForReadyRead();
    QString msg = "";
    while (mTcpSocket->bytesAvailable() > 0) {
        QByteArray array = mTcpSocket->readAll();
        msg.append(array);
    }
    QString decryptedData = decryptData(msg.toUtf8());
    return decryptedData;
}

