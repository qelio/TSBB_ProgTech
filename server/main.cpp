#include <QCoreApplication> // Подключение ядра приложений QT (для использования библиотек и типов данных QT)
#include "mytcpserver.h"
#include "AES.h"

int main(int argc, char *argv[]) // argc, argv - параметры командной строки
{
    QCoreApplication a(argc, argv); // Создание терминала (окна), в котором будет все отображаться
    MyTcpServer myserv;
    return a.exec(); // Запуск консольного приложения на исполнение
}
