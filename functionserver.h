#ifndef FUNCTIONSERVER_H
#define FUNCTIONSERVER_H
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QStringList>

// Функция для авторизации пользователя (на данный момент заглушка)
QByteArray authUser (QString login, QString password);

// Функция для регистрации пользователя (на данный момент заглушка)
QByteArray regUser (QString login, QString password, QString email);

// Функция для вывода статистики по определенному пользователю (на данный момент заглушка)
QByteArray getStat (QString login);

// Функция для проверки правильности решения задачи (на данный момент заглушка)
QByteArray checkNumber (QString task_number, QString variant, QString answer);

// Функция для парсинга получаемой строки
QByteArray mainParser (QString request, long sockId);

#endif // FUNCTIONSERVER_H
