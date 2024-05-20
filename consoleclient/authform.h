#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include "functionclient.h"

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

private slots:
    void on_sign_up_clicked();
    void on_sign_in_clicked();

private:
    Ui::AuthForm *ui;
signals:
    void auth_ok(QString);
};

#endif // AUTHFORM_H
