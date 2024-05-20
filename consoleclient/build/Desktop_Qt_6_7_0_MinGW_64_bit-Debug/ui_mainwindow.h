/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *main_pages;
    QWidget *central_page;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *desired_action;
    QVBoxLayout *verticalLayout;
    QPushButton *shortest_distance_button;
    QPushButton *dichotomy_method_button;
    QPushButton *aes_button;
    QHBoxLayout *horizontalLayout;
    QPushButton *stat_button;
    QPushButton *exit_button;
    QWidget *page_shortest_distance;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *shortest_distance_text;
    QLabel *shortest_distance_condition;
    QLineEdit *shortest_distance_label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *shortest_distance_check;
    QPushButton *shortest_distance_next;
    QPushButton *shortest_distance_return;
    QWidget *page_aes;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *aes_text;
    QLabel *aes_condition;
    QLineEdit *aes_label;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *aes_check;
    QPushButton *aes_next;
    QPushButton *aes_return;
    QWidget *page_dichotomy;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *dichotomy_text;
    QLabel *dichotomy_condition;
    QLineEdit *dichotomy_label;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *dichotomy_check;
    QPushButton *dichotomy_next;
    QPushButton *dichotomy_return;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 538);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        main_pages = new QStackedWidget(centralwidget);
        main_pages->setObjectName("main_pages");
        main_pages->setGeometry(QRect(10, 10, 781, 511));
        central_page = new QWidget();
        central_page->setObjectName("central_page");
        verticalLayoutWidget_2 = new QWidget(central_page);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(20, 40, 741, 431));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        desired_action = new QLabel(verticalLayoutWidget_2);
        desired_action->setObjectName("desired_action");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        desired_action->setFont(font);

        verticalLayout_2->addWidget(desired_action);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        shortest_distance_button = new QPushButton(verticalLayoutWidget_2);
        shortest_distance_button->setObjectName("shortest_distance_button");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shortest_distance_button->sizePolicy().hasHeightForWidth());
        shortest_distance_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(shortest_distance_button);

        dichotomy_method_button = new QPushButton(verticalLayoutWidget_2);
        dichotomy_method_button->setObjectName("dichotomy_method_button");
        sizePolicy.setHeightForWidth(dichotomy_method_button->sizePolicy().hasHeightForWidth());
        dichotomy_method_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(dichotomy_method_button);

        aes_button = new QPushButton(verticalLayoutWidget_2);
        aes_button->setObjectName("aes_button");
        sizePolicy.setHeightForWidth(aes_button->sizePolicy().hasHeightForWidth());
        aes_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(aes_button);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 50, -1, -1);
        stat_button = new QPushButton(verticalLayoutWidget_2);
        stat_button->setObjectName("stat_button");
        sizePolicy.setHeightForWidth(stat_button->sizePolicy().hasHeightForWidth());
        stat_button->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(stat_button);

        exit_button = new QPushButton(verticalLayoutWidget_2);
        exit_button->setObjectName("exit_button");
        sizePolicy.setHeightForWidth(exit_button->sizePolicy().hasHeightForWidth());
        exit_button->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(exit_button);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        main_pages->addWidget(central_page);
        page_shortest_distance = new QWidget();
        page_shortest_distance->setObjectName("page_shortest_distance");
        verticalLayoutWidget_3 = new QWidget(page_shortest_distance);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(20, 30, 721, 451));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        shortest_distance_text = new QLabel(verticalLayoutWidget_3);
        shortest_distance_text->setObjectName("shortest_distance_text");
        shortest_distance_text->setFont(font);
        shortest_distance_text->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(shortest_distance_text);

        shortest_distance_condition = new QLabel(verticalLayoutWidget_3);
        shortest_distance_condition->setObjectName("shortest_distance_condition");

        verticalLayout_3->addWidget(shortest_distance_condition);

        shortest_distance_label = new QLineEdit(verticalLayoutWidget_3);
        shortest_distance_label->setObjectName("shortest_distance_label");

        verticalLayout_3->addWidget(shortest_distance_label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        shortest_distance_check = new QPushButton(verticalLayoutWidget_3);
        shortest_distance_check->setObjectName("shortest_distance_check");

        horizontalLayout_2->addWidget(shortest_distance_check);

        shortest_distance_next = new QPushButton(verticalLayoutWidget_3);
        shortest_distance_next->setObjectName("shortest_distance_next");

        horizontalLayout_2->addWidget(shortest_distance_next);


        verticalLayout_3->addLayout(horizontalLayout_2);

        shortest_distance_return = new QPushButton(verticalLayoutWidget_3);
        shortest_distance_return->setObjectName("shortest_distance_return");

        verticalLayout_3->addWidget(shortest_distance_return);

        main_pages->addWidget(page_shortest_distance);
        page_aes = new QWidget();
        page_aes->setObjectName("page_aes");
        verticalLayoutWidget_5 = new QWidget(page_aes);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(30, 30, 721, 451));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        aes_text = new QLabel(verticalLayoutWidget_5);
        aes_text->setObjectName("aes_text");
        aes_text->setFont(font);
        aes_text->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(aes_text);

        aes_condition = new QLabel(verticalLayoutWidget_5);
        aes_condition->setObjectName("aes_condition");

        verticalLayout_5->addWidget(aes_condition);

        aes_label = new QLineEdit(verticalLayoutWidget_5);
        aes_label->setObjectName("aes_label");

        verticalLayout_5->addWidget(aes_label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        aes_check = new QPushButton(verticalLayoutWidget_5);
        aes_check->setObjectName("aes_check");

        horizontalLayout_4->addWidget(aes_check);

        aes_next = new QPushButton(verticalLayoutWidget_5);
        aes_next->setObjectName("aes_next");

        horizontalLayout_4->addWidget(aes_next);


        verticalLayout_5->addLayout(horizontalLayout_4);

        aes_return = new QPushButton(verticalLayoutWidget_5);
        aes_return->setObjectName("aes_return");

        verticalLayout_5->addWidget(aes_return);

        main_pages->addWidget(page_aes);
        page_dichotomy = new QWidget();
        page_dichotomy->setObjectName("page_dichotomy");
        verticalLayoutWidget_4 = new QWidget(page_dichotomy);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(30, 30, 721, 451));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        dichotomy_text = new QLabel(verticalLayoutWidget_4);
        dichotomy_text->setObjectName("dichotomy_text");
        dichotomy_text->setFont(font);
        dichotomy_text->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(dichotomy_text);

        dichotomy_condition = new QLabel(verticalLayoutWidget_4);
        dichotomy_condition->setObjectName("dichotomy_condition");

        verticalLayout_4->addWidget(dichotomy_condition);

        dichotomy_label = new QLineEdit(verticalLayoutWidget_4);
        dichotomy_label->setObjectName("dichotomy_label");

        verticalLayout_4->addWidget(dichotomy_label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        dichotomy_check = new QPushButton(verticalLayoutWidget_4);
        dichotomy_check->setObjectName("dichotomy_check");

        horizontalLayout_3->addWidget(dichotomy_check);

        dichotomy_next = new QPushButton(verticalLayoutWidget_4);
        dichotomy_next->setObjectName("dichotomy_next");

        horizontalLayout_3->addWidget(dichotomy_next);


        verticalLayout_4->addLayout(horizontalLayout_3);

        dichotomy_return = new QPushButton(verticalLayoutWidget_4);
        dichotomy_return->setObjectName("dichotomy_return");

        verticalLayout_4->addWidget(dichotomy_return);

        main_pages->addWidget(page_dichotomy);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        desired_action->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\266\320\265\320\273\320\260\320\265\320\274\320\276\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265:", nullptr));
        shortest_distance_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\272\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\265\320\263\320\276 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \320\274\320\265\320\266\320\264\321\203 \320\262\320\265\321\200\321\210\320\270\320\275\320\260\320\274\320\270 \320\263\321\200\320\260\321\204\320\260", nullptr));
        dichotomy_method_button->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\277\320\276\320\277\320\276\320\273\320\260\320\274 (\320\274\320\265\321\202\320\276\320\264 \320\264\320\270\321\205\320\276\321\202\320\276\320\274\320\270\320\270)", nullptr));
        aes_button->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265 AES", nullptr));
        stat_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        exit_button->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        shortest_distance_text->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\272\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\265\320\263\320\276 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \320\274\320\265\320\266\320\264\321\203 \320\262\320\265\321\200\321\210\320\270\320\275\320\260\320\274\320\270 \320\263\321\200\320\260\321\204\320\260", nullptr));
        shortest_distance_condition->setText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\265\321\201\321\214 \320\264\320\276\320\273\320\266\320\265\320\275 \320\261\321\213\321\202\321\214 \321\202\320\265\320\272\321\201\321\202 \320\267\320\260\320\264\320\260\321\207\320\270 (\320\267\320\260\320\264\320\260\320\275\320\270\321\217)...", nullptr));
        shortest_distance_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\262\320\265\321\202...", nullptr));
        shortest_distance_check->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        shortest_distance_next->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\275\320\276\320\262\320\276\320\271 \320\267\320\260\320\264\320\260\321\207\320\265", nullptr));
        shortest_distance_return->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \320\262\321\213\320\261\320\276\321\200\321\203 \320\267\320\260\320\264\320\260\320\275\320\270\321\217", nullptr));
        aes_text->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265 AES", nullptr));
        aes_condition->setText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\265\321\201\321\214 \320\264\320\276\320\273\320\266\320\265\320\275 \320\261\321\213\321\202\321\214 \321\202\320\265\320\272\321\201\321\202 \320\267\320\260\320\264\320\260\321\207\320\270 (\320\267\320\260\320\264\320\260\320\275\320\270\321\217)...", nullptr));
        aes_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\262\320\265\321\202...", nullptr));
        aes_check->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        aes_next->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\275\320\276\320\262\320\276\320\271 \320\267\320\260\320\264\320\260\321\207\320\265", nullptr));
        aes_return->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \320\262\321\213\320\261\320\276\321\200\321\203 \320\267\320\260\320\264\320\260\320\275\320\270\321\217", nullptr));
        dichotomy_text->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\277\320\276\320\277\320\276\320\273\320\260\320\274 (\320\274\320\265\321\202\320\276\320\264 \320\264\320\270\321\205\320\276\321\202\320\276\320\274\320\270\320\270)", nullptr));
        dichotomy_condition->setText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\265\321\201\321\214 \320\264\320\276\320\273\320\266\320\265\320\275 \320\261\321\213\321\202\321\214 \321\202\320\265\320\272\321\201\321\202 \320\267\320\260\320\264\320\260\321\207\320\270 (\320\267\320\260\320\264\320\260\320\275\320\270\321\217)...", nullptr));
        dichotomy_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\262\320\265\321\202...", nullptr));
        dichotomy_check->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        dichotomy_next->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\275\320\276\320\262\320\276\320\271 \320\267\320\260\320\264\320\260\321\207\320\265", nullptr));
        dichotomy_return->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \320\262\321\213\320\261\320\276\321\200\321\203 \320\267\320\260\320\264\320\260\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
