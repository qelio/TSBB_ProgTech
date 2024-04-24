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
    // Если соединение готово к чтению сообщений (readyRead), то запускаем slotServerRead
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    // Если соединение получило сигнал о том, что клиент отключился, то запускаем slotClientDisconnected
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
}

// Метод для чтения слота
void MyTcpServer::slotServerRead(){
    // Пока сокет может считать байты, выполняем следующие действия
    while(mTcpSocket->bytesAvailable()>0)
    {
        QString string = "";
        // Создаем массив, куда записываем всё, что было считано
        QByteArray array = mTcpSocket->readAll();
        // Добавление массива в QString
        string.append(array);
        // Вывод полученной строки в консоль
        qDebug() << string.toUtf8();
        // Вывод результата парсинга (результат зависит от типа вызываемой функции)
        mTcpSocket->write(mainParser(string, mTcpSocket->socketDescriptor()));
    }
}

// Метод для закрытия сокета
void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}
