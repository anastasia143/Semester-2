/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created: Wed 6. Mar 23:07:29 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralWidget;
    QLineEdit *result;
    QToolButton *one;
    QToolButton *two;
    QToolButton *three;
    QToolButton *plus;
    QToolButton *four;
    QToolButton *five;
    QToolButton *six;
    QToolButton *seven;
    QToolButton *eight;
    QToolButton *nine;
    QToolButton *minus;
    QToolButton *zero;
    QToolButton *multiplication;
    QToolButton *division;
    QToolButton *equal;
    QToolButton *point;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(393, 317);
        Calculator->setMinimumSize(QSize(393, 317));
        Calculator->setMaximumSize(QSize(393, 317));
        centralWidget = new QWidget(Calculator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        result = new QLineEdit(centralWidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(22, 10, 351, 41));
        QFont font;
        font.setPointSize(14);
        result->setFont(font);
        result->setReadOnly(true);
        one = new QToolButton(centralWidget);
        one->setObjectName(QString::fromUtf8("one"));
        one->setGeometry(QRect(20, 70, 81, 41));
        QFont font1;
        font1.setPointSize(12);
        one->setFont(font1);
        two = new QToolButton(centralWidget);
        two->setObjectName(QString::fromUtf8("two"));
        two->setGeometry(QRect(110, 70, 81, 41));
        two->setFont(font1);
        three = new QToolButton(centralWidget);
        three->setObjectName(QString::fromUtf8("three"));
        three->setGeometry(QRect(200, 70, 81, 41));
        three->setFont(font1);
        plus = new QToolButton(centralWidget);
        plus->setObjectName(QString::fromUtf8("plus"));
        plus->setGeometry(QRect(290, 70, 81, 41));
        plus->setFont(font1);
        four = new QToolButton(centralWidget);
        four->setObjectName(QString::fromUtf8("four"));
        four->setGeometry(QRect(20, 120, 81, 41));
        four->setFont(font1);
        five = new QToolButton(centralWidget);
        five->setObjectName(QString::fromUtf8("five"));
        five->setGeometry(QRect(110, 120, 81, 41));
        five->setFont(font1);
        six = new QToolButton(centralWidget);
        six->setObjectName(QString::fromUtf8("six"));
        six->setGeometry(QRect(200, 120, 81, 41));
        six->setFont(font1);
        seven = new QToolButton(centralWidget);
        seven->setObjectName(QString::fromUtf8("seven"));
        seven->setGeometry(QRect(20, 170, 81, 41));
        seven->setFont(font1);
        eight = new QToolButton(centralWidget);
        eight->setObjectName(QString::fromUtf8("eight"));
        eight->setGeometry(QRect(110, 170, 81, 41));
        eight->setFont(font1);
        nine = new QToolButton(centralWidget);
        nine->setObjectName(QString::fromUtf8("nine"));
        nine->setGeometry(QRect(200, 170, 81, 41));
        nine->setFont(font1);
        minus = new QToolButton(centralWidget);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setGeometry(QRect(290, 120, 81, 41));
        minus->setFont(font1);
        zero = new QToolButton(centralWidget);
        zero->setObjectName(QString::fromUtf8("zero"));
        zero->setGeometry(QRect(20, 220, 81, 41));
        zero->setFont(font1);
        multiplication = new QToolButton(centralWidget);
        multiplication->setObjectName(QString::fromUtf8("multiplication"));
        multiplication->setGeometry(QRect(290, 170, 81, 41));
        multiplication->setFont(font1);
        division = new QToolButton(centralWidget);
        division->setObjectName(QString::fromUtf8("division"));
        division->setGeometry(QRect(290, 220, 81, 41));
        division->setFont(font1);
        equal = new QToolButton(centralWidget);
        equal->setObjectName(QString::fromUtf8("equal"));
        equal->setGeometry(QRect(200, 220, 81, 41));
        equal->setFont(font1);
        point = new QToolButton(centralWidget);
        point->setObjectName(QString::fromUtf8("point"));
        point->setGeometry(QRect(110, 220, 81, 41));
        point->setFont(font1);
        Calculator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Calculator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 393, 21));
        Calculator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Calculator);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Calculator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Calculator);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Calculator->setStatusBar(statusBar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Calculator", 0, QApplication::UnicodeUTF8));
        one->setText(QApplication::translate("Calculator", "1", 0, QApplication::UnicodeUTF8));
        two->setText(QApplication::translate("Calculator", "2", 0, QApplication::UnicodeUTF8));
        three->setText(QApplication::translate("Calculator", "3", 0, QApplication::UnicodeUTF8));
        plus->setText(QApplication::translate("Calculator", "+", 0, QApplication::UnicodeUTF8));
        four->setText(QApplication::translate("Calculator", "4", 0, QApplication::UnicodeUTF8));
        five->setText(QApplication::translate("Calculator", "5", 0, QApplication::UnicodeUTF8));
        six->setText(QApplication::translate("Calculator", "6", 0, QApplication::UnicodeUTF8));
        seven->setText(QApplication::translate("Calculator", "7", 0, QApplication::UnicodeUTF8));
        eight->setText(QApplication::translate("Calculator", "8", 0, QApplication::UnicodeUTF8));
        nine->setText(QApplication::translate("Calculator", "9", 0, QApplication::UnicodeUTF8));
        minus->setText(QApplication::translate("Calculator", "-", 0, QApplication::UnicodeUTF8));
        zero->setText(QApplication::translate("Calculator", "0", 0, QApplication::UnicodeUTF8));
        multiplication->setText(QApplication::translate("Calculator", "*", 0, QApplication::UnicodeUTF8));
        division->setText(QApplication::translate("Calculator", "/", 0, QApplication::UnicodeUTF8));
        equal->setText(QApplication::translate("Calculator", "=", 0, QApplication::UnicodeUTF8));
        point->setText(QApplication::translate("Calculator", ".", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
