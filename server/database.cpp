#include "database.h"

database *database::p_instance = nullptr;
databaseDestroyer database::destroyer;

// INSERT INTO users (login, password, email, stat, sockId) VALUES ('qelio', '3627909a29c31381a071ec27f7c9ca97726182aed29a7ddd2e54353322cfb30abb9e3a6df2ac2c20fe23436311d678564d0c8d305930575f60e2d3d048184d79', 'slava.samokhvalov@mail.ru', 0, 0);

// Метод добавления (открытия) базы данных
database::database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\slava\\Downloads\\ProektTP-master\\server\\base.db");
    if (!db.open()) {
        qDebug() << "Error: database opening error";
    }
}

// Метод для создания таблицы в базе данных
bool database::createTable() {
    QSqlQuery query(db);
    return query.exec("CREATE TABLE users(id INTEGER PRIMARY KEY NOT NULL, login VARCHAR(20) NOT NULL, password VARCHAR(100) NOT NULL, email VARCHAR(30) NOT NULL, stat INTEGER NOT NULL, sockid INTEGER NOT NULL);");
}

// Деструктор класса database
database::~database() {
    db.close();
}

// Механизм глобального доступа к единственному экземпляру класса
database &database::getInstance() {
    if (!p_instance) {
        p_instance = new database();
        // p_instance->createTable();
    }
    return *p_instance;
}

// Деструктор класса databaseDestroyer
databaseDestroyer::~databaseDestroyer() {
    delete p_instance;
}

// Метод инициализации (копирование указателя из аргумента в указатель, который является свойством класса)
void databaseDestroyer::initialize(database *p) {
    p_instance = p;
}

int database::AuthUser(QString login, QString password, long sockId) {
    QString query = "SELECT CASE WHEN COUNT(*) > 0 THEN id ELSE '0' END AS user_id FROM users WHERE login = '%1' AND password = '%2'";
    QStringList answer = p_instance->queryToDatabase(query.arg(login).arg(password), 1, true);
    if (answer[0].toInt() != 0) {
        query = "UPDATE users SET sockId = '%1' WHERE login = '%2' AND password = '%3'";
        QStringList update_sockId = p_instance->queryToDatabase(query.arg(sockId).arg(login).arg(password), 0, false);
        if (update_sockId[0] != "error_sql") {
            return answer[0].toInt();
        }
        return 0;
    }
    return 0;
}



QStringList database::queryToDatabase(QString str, int count_columns, bool select_query) {
    // Здесь будет реализована обработка запросов к базе данных
    QSqlQuery query(db);
    QStringList res;
    query.prepare(str);
    // qDebug() << str;
    if (!query.exec()){
        qDebug() << "Error SQL:" << query.lastError().text();
        res.append("error_sql");
        return res;
    }
    if (select_query) {
        while (query.next()) {
            for (int i = 0; i < count_columns; i++){
                res.append(query.value(i).toString());
            }
        }
    }
    res.append("success_sql");
    return res;
}
