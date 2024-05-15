#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authform.h"

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

private slots:
    void on_dichotomy_method_button_clicked();
    void on_aes_button_clicked();
    void on_shortest_distance_button_clicked();
    void on_aes_return_clicked();
    void on_dichotomy_return_clicked();
    void on_shortest_distance_return_clicked();

private:
    Ui::MainWindow *ui;
    AuthForm * auth_ui;
};
#endif // MAINWINDOW_H
