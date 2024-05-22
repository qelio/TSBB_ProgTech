#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dichotomy_answer->setVisible(false);
    on_dichotomy_next_clicked();
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
    ui->stat1->setText("Статистика по \"Метод Дихотомии\": " + stats[1].trimmed() + "\n" + "Статистика по \"Алгоритм Дейкстры\": " + stats[2].trimmed());
}

void MainWindow::on_dichotomy_next_clicked() {
    ui->dichotomy_answer->setVisible(false);
    ui->dichotomy_label->setText("");
    left = getRandomNumber(1, 5);
    right = left + getRandomNumber(1, 5);
    count_iters = getRandomNumber(1, 5);
    a = getRandomNumber(1, 5);
    b = getRandomNumber(1, 5);
    c = getRandomNumber(1, 5);
    ui->dichotomy_condition->setText("Найдите значение функции на " + QString::number(count_iters) + "-ой итерации метода: \n\nФункция: " + QString::number(a) + "x^2 + " + QString::number(b) + "x + " + QString::number(c) + ",       " + QString::number(left) + " <= x <= " + QString::number(right));
}

void MainWindow::on_dichotomy_check_clicked() {
    ui->dichotomy_answer->setVisible(true);
    if (checkDichotomyMethod(left, right, count_iters, a, b, c, ui->dichotomy_label->text().toDouble())) {
        ui->dichotomy_answer->setText("Вы решили задачу верно!");
    }
    else {
        ui->dichotomy_answer->setText("Вы решили задачу неверно!");
    }
}


void MainWindow::on_stat_button_clicked() {
    get_stat(this->login);
}
