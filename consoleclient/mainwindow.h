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

private slots:
    void on_dichotomy_method_button_clicked();
    void on_shortest_distance_button_clicked();
    void on_dichotomy_return_clicked();
    void on_shortest_distance_return_clicked();
    void on_exit_button_clicked();
    void on_stat_button_clicked();

private:
    QString login;
    Ui::MainWindow *ui;
    AuthForm * auth_ui;

signals:
    void close_window();
};
#endif // MAINWINDOW_H
