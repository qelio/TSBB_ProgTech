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
    bool createTable();
    QStringList queryToDatabase(QString str, int count_columns, bool select_query);

public:

    int AuthUser(QString login, QString password, long sockId);
    bool RegUser(QString login, QString password, QString email, long sockId);
    bool LogOutUser(long sockId);
    bool UpdateStat1True(long sockId);
    bool UpdateStat2True(long sockId);
    bool UpdateStat1False(long sockId);
    bool UpdateStat2False(long sockId);
    bool ActiveSessionUser (QString login, long sockId);
    QStringList StatUser (QString login, long sockId);
    static database& getInstance();

};

#endif // DATABASE_H
