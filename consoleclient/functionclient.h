#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QString>
#include <QStringList>
#include "singletonclient.h"

bool auth(QString login, QString password);

bool reg(QString login, QString password, QString email);

QStringList get_stat_login(QString login);

int getRandomNumber(int min, int max);

bool checkDichotomyMethod(int left, int right, int count_iters, int a, int b, int c, double ans);

#endif // FUNCTIONSFORCLIENT_H
