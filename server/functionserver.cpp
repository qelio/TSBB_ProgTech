#include "functionserver.h"

// Функция для авторизации пользователя (на данный момент заглушка)
QByteArray authUser (QString login, QString password, long sockId) {
    QString password_sha = QString::fromStdString(sha512(password.toStdString()));
    int user_id = database::getInstance().AuthUser(login, password_sha, sockId);
    if (user_id != 0) {
        return "auth+\r\n";
    }
    return "auth-\r\n";
}

// Функция для регистрации пользователя (на данный момент заглушка)
QByteArray regUser (QString login, QString password, QString email) {
    if (login == "user" && password == "test" && email == "test@mail.ru") {
        return ("reg+&" + login + "\r\n").toUtf8();
    }
    else {
        return "reg-\r\n";
    }
}

// Функция для вывода статистики по определенному пользователю (на данный момент заглушка)
QByteArray getMyStat (long sockId) {
    return "stat\r\n";
}

// Функция для вывода статистики по всем пользователям (на данный момент заглушка)
QByteArray getAllStat () {
    return "stat\r\n";
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
        return regUser(command[1], command[2], command[3].trimmed());
    }
    else if (command[0] == "stat") {
        return getMyStat(sockId);
    }
    else {
        return "incorrent\r\n";
    }
}
