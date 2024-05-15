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
    ui->email->setVisible(true);
    ui->email_label->setVisible(true);
    ui->sign_in->setText("Вернуться ко входу");
}

void AuthForm::on_sign_in_clicked() {
    if (ui->email->isVisible()) {
        ui->email->setVisible(false);
        ui->email_label->setVisible(false);
        ui->sign_in->setText("Войти");
    }
    else {
        // Реализация алгоритма входа в аккаунт
    }
}
