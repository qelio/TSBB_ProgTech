#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_dichotomy_method_button_clicked() {
    ui->main_pages->setCurrentIndex(3);
}

void MainWindow::on_shortest_distance_button_clicked() {
    ui->main_pages->setCurrentIndex(1);
}

void MainWindow::on_dichotomy_return_clicked() {
    ui->main_pages->setCurrentIndex(0);
}

void MainWindow::on_shortest_distance_return_clicked() {
    ui->main_pages->setCurrentIndex(0);
}

void MainWindow::on_exit_button_clicked() {
    emit close_window();
}

void MainWindow::get_stat(QString login) {
    this->login = login;
    QStringList stats = get_stat_login(login);
    ui->stat1->setText("Статистика по задаче №1: " + stats[1].trimmed() + "\n" + "Статистика по задаче №2: " + stats[2].trimmed());
}

void MainWindow::on_stat_button_clicked() {
    get_stat(this->login);
}
