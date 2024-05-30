#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dichotomy_answer->setVisible(false);
    on_dichotomy_next_clicked();
    ui->dichotomy_answer->setVisible(false);
    on_shortest_distance_next_clicked();
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

void MainWindow::on_shortest_distance_check_clicked() {
    ui->shortest_distance_answer->setVisible(true);
    if (checkShortestDistance(ui->shortest_distance_label->text().toInt(), graph, s, t)) {
        ui->shortest_distance_answer->setText("Вы решили задачу верно!");
    }
    else {
        ui->shortest_distance_answer->setText("Вы решили задачу неверно!");
    }
}

void MainWindow::on_shortest_distance_next_clicked() {
    ui->shortest_distance_answer->setVisible(false);
    ui->shortest_distance_label->setText("");
    current_text = "";
    srand(time(nullptr));
    std::vector<std::vector<int>> graph_current(NUM_VERTICES, std::vector<int>(NUM_VERTICES, INF));
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = i + 1; j < NUM_VERTICES; j++) {
            if (i != j) {
                int distance = getRandomNumber(1, 10);
                graph_current[i][j] = distance;
                graph_current[j][i] = distance;
            }
        }
    }
    graph = graph_current;
    s = getRandomNumber(0, NUM_VERTICES - 1);
    t = getRandomNumber(0, NUM_VERTICES - 1);
    while (s == t) {
        t = getRandomNumber(0, NUM_VERTICES - 1);
    }

    // Вывод сгенерированной информации
    current_text += "Граф с рандомными расстояниями между вершинами:\n\n";
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            if (graph[i][j] == INF) {
                current_text += "INF\t";
            } else {
                current_text += QString::number(graph[i][j]) + "\t";
            }
        }
        current_text += "\n";
    }
    current_text += "\nНачальная вершина s: " + QString::number(s) + "\n";
    current_text += "Целевая вершина t: " + QString::number(t) + "\n";
    qDebug() << current_text;
    ui->shortest_distance_condition->setText(current_text);

}

void MainWindow::on_stat_button_clicked() {
    get_stat(this->login);
}
