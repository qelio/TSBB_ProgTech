#include "database.h"

database *database::p_instance = nullptr;
databaseDestroyer database::destroyer;

// Метод добавления (открытия) базы данных
database::database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("base.db");
    if (!db.open()) {
        qDebug() << "Error: database opening error";
    }
}

// Метод для создания таблицы в базе данных
bool database::createTable() {
    QSqlQuery query(db);
    return query.exec("CREATE TABLE users(id INTEGER PRIMARY KEY NOT NULL, login VARCHAR(20) NOT NULL, password VARCHAR(100) NOT NULL, email VARCHAR(30) NOT NULL, stat INTEGER NOT NULL);");
}

// Деструктор класса database
database::~database() {
    db.close();
}

// Механизм глобального доступа к единственному экземпляру класса
database &database::getInstance() {
    if (!p_instance) {
        p_instance = new database();
        p_instance->createTable();
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

QStringList database::queryToDatabase(QStringList str) {
    // Здесь будет реализована обработка запросов к базе данных
    QSqlQuery query(db);
    QStringList res;
    return res;
}
