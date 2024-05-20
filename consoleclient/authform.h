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

signals:
    void sign_in(QString login);
    void sign_up(QString login);

private:
    Ui::AuthForm *ui;

};

#endif // AUTHFORM_H
