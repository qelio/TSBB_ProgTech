#include "functionserver.h"

// Функция для авторизации пользователя (на данный момент заглушка)
QByteArray authUser (QString login, QString password) {
    if (login == "user" && password == "test") {
        return ("auth+&" + login + "\r\n").toUtf8();
    }
    else {
        return "auth-\r\n";
    }
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
QByteArray getStat (QString login) {
    return "stat&3&6&21\r\n";
}

// Функция для проверки правильности решения задачи (на данный момент заглушка)
QByteArray checkNumber (QString task_number, QString variant, QString answer) {
    if (task_number == "1" && variant == "2" && answer == "3") {
        return "check+\r\n";
    }
    else {
        return "check-\r\n";
    }
}

// Функция для парсинга получаемой строки
QByteArray mainParser (QString request, long sockId) {
    // Разделение строки по разделителю "&"
    QStringList command = request.split("&");
    // Далее идет проверка команд, если команда не соответствует, то возвращаем "incrorrect"
    // Метод trimmed() необходим для исключения из строки такие символы, как \r, \n (whitespace characters)
    if (command[0] == "auth") {
        return authUser(command[1], command[2].trimmed());
    }
    else if (command[0] == "reg") {
        return regUser(command[1], command[2], command[3].trimmed());
    }
    else if (command[0] == "stat") {
        return getStat(command[1].trimmed());
    }
    else if (command[0] == "check") {
        return checkNumber(command[1], command[2], command[3].trimmed());
    }
    else {
        return "incorrent\r\n";
    }
}
