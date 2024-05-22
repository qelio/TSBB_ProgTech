#ifndef FUNCTIONSERVER_H
#define FUNCTIONSERVER_H
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QStringList>
#include <QRegularExpression>>
#include "sha512.h"
#include "database.h"
#include "dichotomymethod.h"

// Функция для проверки корретности email
bool isValidEmail(QString email);

// Функция для авторизации пользователя (на данный момент заглушка)
QByteArray authUser (QString login, QString password, long sockId);

// Функция для регистрации пользователя (на данный момент заглушка)
QByteArray regUser (QString login, QString password, QString email, long sockId);

// Функция для выхода из аккаунта
bool logOutUser (long sockId);

// Функция для вывода статистики по определенному пользователю (на данный момент заглушка)
QByteArray getMyStat (long sockId);

// Функция для парсинга получаемой строки
QByteArray mainParser (QString request, long sockId);

QByteArray task_1(double left, double right, int count_iters, double a, double b, double c, double ans, long sockId);

#endif // FUNCTIONSERVER_H
