#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QString>
#include <QStringList>
#include "singletonclient.h"

bool auth(QString login, QString password);

bool reg(QString login, QString password, QString email);

QStringList get_stat_login(QString login);

#endif // FUNCTIONSFORCLIENT_H
