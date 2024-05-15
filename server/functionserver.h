#ifndef FUNCTIONSERVER_H
#define FUNCTIONSERVER_H
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QStringList>
#include <QRegularExpression>>
#include "sha512.h"
#include "database.h"

// Функция для проверки корретности email
bool isValidEmail(QString email);

// Функция для авторизации пользователя (на данный момент заглушка)
QByteArray authUser (QString login, QString password);

// Функция для регистрации пользователя (на данный момент заглушка)
QByteArray regUser (QString login, QString password, QString email);

// Функция для вывода статистики по определенному пользователю (на данный момент заглушка)
QByteArray getMyStat (long sockId);

// Функция для вывода статистики по всем пользователям (на данный момент заглушка)
QByteArray getAllStat ();

// Функция для парсинга получаемой строки
QByteArray mainParser (QString request, long sockId);

#endif // FUNCTIONSERVER_H
