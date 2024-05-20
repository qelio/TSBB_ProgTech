#include "functionserver.h"

// Функция для проверки корретности email
bool isValidEmail(QString email) {
    QRegularExpression regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex.match(email).hasMatch();
}

// Функция для авторизации пользователя
QByteArray authUser (QString login, QString password, long sockId) {
    qDebug() << sockId;
    QString password_sha = QString::fromStdString(sha512(password.toStdString()));
    int user_id = database::getInstance().AuthUser(login, password_sha, sockId);
    if (user_id != 0) {
        return "auth+\r\n";
    }
    return "auth-\r\n";
}

// Функция для регистрации пользователя
QByteArray regUser (QString login, QString password, QString email, long sockId) {
    if (isValidEmail(email)) {
        QString password_sha = QString::fromStdString(sha512(password.toStdString()));
        bool success_reg = database::getInstance().RegUser(login, password_sha, email, sockId);
        if (success_reg) {
            return "reg+\r\n";
        }
        return "reg-\r\n";
    }
    return "reg-\r\n";
}

// Функция для вывода статистики по определенному пользователю (на данный момент заглушка)
QByteArray getMyStat (QString login, long sockId) {
    if (database::getInstance().ActiveSessionUser(login, sockId)) {
        QStringList stat = database::getInstance().StatUser(login, sockId);
        return "stat&" + stat[0].toUtf8() + "&" + stat[1].toUtf8() + "\r\n";
    }
    return "stat-\r\n";
}

bool logOutUser (long sockId) {
    qDebug() << sockId;
    if (database::getInstance().LogOutUser(sockId)) {
        return true;
    }
    return false;
}

// Функция для парсинга получаемой строки
QByteArray mainParser (QString request, long sockId) {
    // Разделение строки по разделителю "&"
    QStringList command = request.split("&");
    // Далее идет проверка команд, если команда не соответствует, то возвращаем "incrorrect"
    // Метод trimmed() необходим для исключения из строки такие символы, как \r, \n (whitespace characters)
    if (command[0] == "auth") {
        return authUser(command[1], command[2].trimmed(), sockId);
    }
    else if (command[0] == "reg") {
        return regUser(command[1], command[2], command[3].trimmed(), sockId);
    }
    else if (command[0] == "stat") {
        return getMyStat(command[1].trimmed(), sockId);
    }
    else {
        return "incorrent\r\n";
    }
}
