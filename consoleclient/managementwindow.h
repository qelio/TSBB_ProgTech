#ifndef MANAGEMENTWINDOW_H
#define MANAGEMENTWINDOW_H

#include "authform.h"
#include "mainwindow.h"

#include <QObject>
#include <QDebug>


class ManagementWindow : public QObject
{
    Q_OBJECT;

private:
    AuthForm* auth_form;
    MainWindow* main_form;

public:
    ManagementWindow(QObject * parent=nullptr);

private slots:
    void sign_in(QString login);
    void sign_up(QString login);
    void slot_exit();

signals:
    void get_stat(QString login);
};


#endif // MANAGEMENTWINDOW_H
