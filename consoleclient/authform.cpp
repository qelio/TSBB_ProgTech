#include "authform.h"
#include "ui_authform.h"

AuthForm::AuthForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    ui->email->setVisible(false);
    ui->email_label->setVisible(false);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_sign_up_clicked() {
    if (!ui->email->isVisible()) {
        ui->email->setVisible(true);
        ui->email_label->setVisible(true);
        ui->sign_in->setText("Вернуться ко входу");
    }
    else {
        if (reg(ui->login_label->text(), ui->password_label->text(), ui->email_label->text())) {
            emit sign_up(ui->login_label->text());
        }
        else {
            // Выводим ошибку регистрации
        }
    }
}

void AuthForm::on_sign_in_clicked() {
    if (ui->email->isVisible()) {
        ui->email->setVisible(false);
        ui->email_label->setVisible(false);
        ui->sign_in->setText("Войти");
    }
    else {
        if (auth(ui->login_label->text(), ui->password_label->text())) {
            emit sign_up(ui->login_label->text());
        }
        else {
            // Выводим ошибку авторизации
        }
    }
}
