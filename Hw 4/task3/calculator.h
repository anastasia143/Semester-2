#pragma once
#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();
    
private:
    Ui::Calculator *ui;
    int operation;
    QString arg1;
    QString arg2;
    bool isItArg1;

public slots:
    void numberPressed(int number);
    void signPressed(int sign);
    void equalPressed();
    void pointPressed();
};


