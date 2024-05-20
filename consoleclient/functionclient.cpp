#include "functionclient.h"

bool auth(QString login, QString password) {
    QString res = SingletonClient::getInstance()->send_msg_to_server("auth&" + login + "&" + password);
    if (res == "auth+\r\n") {
        return true;
    }
    else {
        return false;
    }
}

bool reg(QString login, QString password, QString email) {
    QString res = SingletonClient::getInstance()->send_msg_to_server("reg&" + login + "&" + password + "&" + email);
    if (res == "reg+\r\n") {
        return true;
    }
    else {
        return false;
    }
}

QStringList get_stat_login(QString login) {
    QString res = SingletonClient::getInstance()->send_msg_to_server("stat&" + login);
    QStringList stats = res.split("&");
    return stats;
}
