/********************************************************************************
** Form generated from reading UI file 'authform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHFORM_H
#define UI_AUTHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *hello_text;
    QLabel *login;
    QLineEdit *login_label;
    QLabel *password;
    QLineEdit *password_label;
    QLabel *email;
    QLineEdit *email_label;
    QHBoxLayout *horizontalLayout;
    QPushButton *sign_in;
    QPushButton *sign_up;

    void setupUi(QWidget *AuthForm)
    {
        if (AuthForm->objectName().isEmpty())
            AuthForm->setObjectName("AuthForm");
        AuthForm->resize(624, 347);
        verticalLayoutWidget = new QWidget(AuthForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 20, 531, 297));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        hello_text = new QLabel(verticalLayoutWidget);
        hello_text->setObjectName("hello_text");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        hello_text->setFont(font);
        hello_text->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(hello_text);

        login = new QLabel(verticalLayoutWidget);
        login->setObjectName("login");

        verticalLayout->addWidget(login);

        login_label = new QLineEdit(verticalLayoutWidget);
        login_label->setObjectName("login_label");

        verticalLayout->addWidget(login_label);

        password = new QLabel(verticalLayoutWidget);
        password->setObjectName("password");

        verticalLayout->addWidget(password);

        password_label = new QLineEdit(verticalLayoutWidget);
        password_label->setObjectName("password_label");

        verticalLayout->addWidget(password_label);

        email = new QLabel(verticalLayoutWidget);
        email->setObjectName("email");

        verticalLayout->addWidget(email);

        email_label = new QLineEdit(verticalLayoutWidget);
        email_label->setObjectName("email_label");

        verticalLayout->addWidget(email_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 50, -1, -1);
        sign_in = new QPushButton(verticalLayoutWidget);
        sign_in->setObjectName("sign_in");

        horizontalLayout->addWidget(sign_in);

        sign_up = new QPushButton(verticalLayoutWidget);
        sign_up->setObjectName("sign_up");

        horizontalLayout->addWidget(sign_up);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AuthForm);

        QMetaObject::connectSlotsByName(AuthForm);
    } // setupUi

    void retranslateUi(QWidget *AuthForm)
    {
        AuthForm->setWindowTitle(QCoreApplication::translate("AuthForm", "Form", nullptr));
        hello_text->setText(QCoreApplication::translate("AuthForm", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214!", nullptr));
        login->setText(QCoreApplication::translate("AuthForm", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        login_label->setText(QString());
        login_label->setPlaceholderText(QCoreApplication::translate("AuthForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275...", nullptr));
        password->setText(QCoreApplication::translate("AuthForm", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        password_label->setText(QString());
        password_label->setPlaceholderText(QCoreApplication::translate("AuthForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214...", nullptr));
        email->setText(QCoreApplication::translate("AuthForm", "\320\220\320\264\321\200\320\265\321\201 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\277\320\276\321\207\321\202\321\213:", nullptr));
        email_label->setText(QString());
        email_label->setPlaceholderText(QCoreApplication::translate("AuthForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 e-mail...", nullptr));
        sign_in->setText(QCoreApplication::translate("AuthForm", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        sign_up->setText(QCoreApplication::translate("AuthForm", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthForm: public Ui_AuthForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHFORM_H
