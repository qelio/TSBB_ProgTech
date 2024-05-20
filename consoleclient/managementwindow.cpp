#include "managementwindow.h"

ManagementWindow::ManagementWindow (QObject *parent) : QObject(parent) {
    this->auth_form = new AuthForm();
    this->main_form = new MainWindow();
    auth_form->show();
    connect(auth_form, &AuthForm::sign_in, this, &ManagementWindow::sign_in);
    connect(auth_form, &AuthForm::sign_up, this, &ManagementWindow::sign_up);
    connect(main_form, &MainWindow::close_window, this, &ManagementWindow::slot_exit);

}

void ManagementWindow::sign_in(QString login) {
    this->auth_form->close();
    this->main_form->show();
    this->main_form->get_stat(login);
}

void ManagementWindow::sign_up(QString login) {
    this->auth_form->close();
    this->main_form->show();
    this->main_form->get_stat(login);
}

void ManagementWindow::slot_exit() {
    // auth_form->show();
    // main_form->close();
    main_form->close();
}
