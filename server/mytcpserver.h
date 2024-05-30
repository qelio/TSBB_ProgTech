// Если не определена константа MYTCPSERVER_H, то необходимо ее определить и выполнить код
// Это гарантирует, что описание класса при линковке будет в единственном экземпляре
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject> // Необходима для того, чтобы работал механизм сигналов и слотов (слот - блок команд, который будет выполняться при появлении сигнала)
#include <QString>
#include <QTcpServer> // Готовая библиотека (шаблон для написания сервера)
#include <QTcpSocket> // Необходима для установления соединения

#include <QtNetwork> // Необходима для сетевого взаимодействи
#include <QByteArray> // Для побайтовой передачи данных (массив байтов)
#include <QDebug> // Необходима для вывода в консоль каких-либо сообщений
#include <QMap>
#include "AES.h"

class MyTcpServer : public QObject // Является наследником QObject, чтобы работал механизм сигналов и слотов
{
    Q_OBJECT // Константа, в которой находится блок команд, который будет использоваться в классе
public:
    QByteArray encryptData(const QString& data);
    QString decryptData(const QByteArray& encryptedData);
    explicit MyTcpServer(QObject *parent = nullptr); // Инициализирующий конструктор, со значение родительского объекта пустым
    ~MyTcpServer(); // Деструктор
public slots:
    // Ниже описаны методы, которые будут происходить при срабатывании какого-либо сигнала
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    QTcpServer * mTcpServer; // Создание сервера
    QTcpSocket * mTcpSocket; // Создание сокета (для однопользовательского сервера), задание соединения с сервером
    //int server_status;
    QMap<int, QTcpSocket*> mSocketDescriptors;
};
#endif // MYTCPSERVER_H







