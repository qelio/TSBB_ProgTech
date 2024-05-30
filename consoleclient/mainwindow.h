#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authform.h"
#include "functionclient.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void get_stat(QString login);

private:
    int left = getRandomNumber(1, 5);
    int right = left + getRandomNumber(1, 5);
    int count_iters = getRandomNumber(1, 5);
    int a = getRandomNumber(1, 5);
    int b = getRandomNumber(1, 5);
    int c = getRandomNumber(1, 5);

private slots:
    void on_dichotomy_method_button_clicked();
    void on_shortest_distance_button_clicked();
    void on_dichotomy_return_clicked();
    void on_shortest_distance_return_clicked();
    void on_exit_button_clicked();
    void on_stat_button_clicked();
    void on_dichotomy_next_clicked();
    void on_dichotomy_check_clicked();
    void on_shortest_distance_check_clicked();
    void on_shortest_distance_next_clicked();

private:
    QString login;
    Ui::MainWindow *ui;
    AuthForm * auth_ui;
    const int NUM_VERTICES = 5;
    const int INF = INT_MAX;
    std::vector<std::vector<int>> graph;
    QString current_text = "";
    int s, t;

signals:
    void close_window();
};
#endif // MAINWINDOW_H
