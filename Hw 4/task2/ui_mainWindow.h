/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created: Wed 6. Mar 00:24:16 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSpinBox *firstNumber;
    QSpinBox *secondNumber;
    QComboBox *sign;
    QLineEdit *result;
    QLabel *equal;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(446, 191);
        MainWindow->setMinimumSize(QSize(446, 191));
        MainWindow->setMaximumSize(QSize(446, 191));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        firstNumber = new QSpinBox(centralWidget);
        firstNumber->setObjectName(QString::fromUtf8("firstNumber"));
        firstNumber->setGeometry(QRect(40, 50, 71, 61));
        QFont font1;
        font1.setPointSize(28);
        font1.setBold(false);
        font1.setWeight(50);
        firstNumber->setFont(font1);
        firstNumber->setMaximum(99);
        secondNumber = new QSpinBox(centralWidget);
        secondNumber->setObjectName(QString::fromUtf8("secondNumber"));
        secondNumber->setGeometry(QRect(210, 50, 71, 61));
        secondNumber->setFont(font1);
        secondNumber->setMaximum(99);
        sign = new QComboBox(centralWidget);
        sign->setObjectName(QString::fromUtf8("sign"));
        sign->setGeometry(QRect(130, 50, 61, 61));
        QFont font2;
        font2.setPointSize(24);
        sign->setFont(font2);
        result = new QLineEdit(centralWidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setEnabled(true);
        result->setGeometry(QRect(320, 50, 91, 61));
        result->setFont(font1);
        result->setMouseTracking(false);
        result->setAcceptDrops(true);
        result->setLayoutDirection(Qt::RightToLeft);
        result->setReadOnly(true);
        equal = new QLabel(centralWidget);
        equal->setObjectName(QString::fromUtf8("equal"));
        equal->setEnabled(false);
        equal->setGeometry(QRect(290, 70, 21, 21));
        QFont font3;
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setWeight(50);
        equal->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 446, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        sign->clear();
        sign->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8)
        );
        result->setText(QString());
        equal->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
