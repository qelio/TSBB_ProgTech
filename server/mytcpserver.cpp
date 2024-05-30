#include "mytcpserver.h"
#include "functionserver.h"

MyTcpServer::~MyTcpServer() // Деструктор - закрытие сервера
{
    mTcpServer->close();
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this); // this необходим для привязки к текущему объекту

    // Механизм сигналов и слотов (связывание сигнала с тем действием, которое должен совершить сервер)
    // mTcpServer - источник сигнала; &QTcpServer::newConnection - тип сигнала; this - получатель сигнала; &MyTcpServer::slotNewConnection - действие, которое необходимо выполнить
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    // Прослушивание канала с любого IP-адреса на порт 33333
    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        // Если не можем прослушать, то выводим соответствующее сообщение
        qDebug() << "server is not started";
    } else {
        // server_status=1;
        // Если можем прослушать, то выводим соответствующее сообщение
        qDebug() << "server is started";
    }
}

// Метод для создания нового подключения
void MyTcpServer::slotNewConnection(){
    // Инициализация указателя mTcpSocket, то есть указание места в памяти, где расположен идентифкатор соединения
    mTcpSocket = mTcpServer->nextPendingConnection();
    int socketDescriptor = mTcpSocket->socketDescriptor();
    mSocketDescriptors[socketDescriptor] = mTcpSocket;
    // Если соединение готово к чтению сообщений (readyRead), то запускаем slotServerRead
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    // Если соединение получило сигнал о том, что клиент отключился, то запускаем slotClientDisconnected
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
}

QByteArray MyTcpServer::encryptData(const QString& data)
{
    unsigned char key[16] = "123456789012345";
    AES aes(key);
    QByteArray encryptedText = aes.encrypt(data);
    return encryptedText;
}

QString MyTcpServer::decryptData(const QByteArray& encryptedData)
{
    unsigned char key[16] = "123456789012345";
    AES aes(key);
    QString decrypted = aes.decrypt(encryptedData);
    return decrypted;
}

// Метод для чтения слота
void MyTcpServer::slotServerRead(){
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    // Пока сокет может считать байты, выполняем следующие действия
    while(socket->bytesAvailable()>0)
    {
        QString string = "";
        // Создаем массив, куда записываем всё, что было считано
        QByteArray array = socket->readAll();
        // Добавление массива в QString
        string.append(array);
        // Вывод полученной строки в консоль
        qDebug() << string.toUtf8();
        QString decryptedData = decryptData(string.toUtf8());
        QByteArray encryptedData = encryptData(mainParser(decryptedData, socket->socketDescriptor()));
        // Вывод результата парсинга (результат зависит от типа вызываемой функции)
        socket->write(encryptedData);
    }
}

// Метод для закрытия сокета
void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    int socketDescriptor = mSocketDescriptors.key(socket);
    logOutUser(socketDescriptor);

    mSocketDescriptors.remove(socketDescriptor);
    socket->close();
}
