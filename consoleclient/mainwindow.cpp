#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth_ui = new AuthForm;
    auth_ui->show();
    connect(auth_ui,&AuthForm::auth_ok,this, &MainWindow::slot_on_auth);
}

void MainWindow::slot_on_auth(QString log)
{
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dichotomy_method_button_clicked() {
    ui->main_pages->setCurrentIndex(3);
}

void MainWindow::on_aes_button_clicked() {
    ui->main_pages->setCurrentIndex(2);
}

void MainWindow::on_shortest_distance_button_clicked() {
    ui->main_pages->setCurrentIndex(1);
}

void MainWindow::on_aes_return_clicked() {
    ui->main_pages->setCurrentIndex(0);
}

void MainWindow::on_dichotomy_return_clicked() {
    ui->main_pages->setCurrentIndex(0);
}

void MainWindow::on_shortest_distance_return_clicked() {
    ui->main_pages->setCurrentIndex(0);
}
