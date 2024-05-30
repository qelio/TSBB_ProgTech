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

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

bool checkDichotomyMethod(int left, int right, int count_iters, int a, int b, int c, double ans) {
    QString res = SingletonClient::getInstance()->send_msg_to_server("check&task_1&" + QString::number(left) + "&" + QString::number(right) + "&" + QString::number(count_iters) + "&" + QString::number(a) + "&" + QString::number(b) + "&" + QString::number(c) + "&" + QString::number(ans));
    qDebug() << res;
    if (res == "check+\r\n") {
        return true;
    }
    else {
        return false;
    }
}

bool checkShortestDistance(int user_answer, std::vector<std::vector<int>>& graph, int s, int t) {
    QString msg = "check&task_2&" + QString::number(user_answer) + "&" + QString::number(s) + "&" + QString::number(t) + "&";
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = i + 1; j < NUM_VERTICES; j++) {
            if (i != j) {
                msg += QString::number(graph[i][j]) + "&";
            }
        }
        // msg += "&";
    }
    qDebug() << msg;
    QString res = SingletonClient::getInstance()->send_msg_to_server(msg);
    qDebug() << res;
    if (res == "check+\r\n") {
        return true;
    }
    else {
        return false;
    }
}
