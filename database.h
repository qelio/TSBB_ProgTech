#ifndef DATABASE_H
#define DATABASE_H

#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QStringList>

class database;

class databaseDestroyer
{
private:
    database * p_instance;
public:
    ~databaseDestroyer();
    void initialize(database * p);
};

class database {
private:
    static database *p_instance;
    static databaseDestroyer destroyer;
    QSqlDatabase db;
    database();
    ~database();
    database(const database&) = delete;
    void operator= (const database&) = delete;
    friend class databaseDestroyer;

public:
    bool createTable();
    static database& getInstance();
    QStringList queryToDatabase(QStringList str);
};

#endif // DATABASE_H
