#pragma once
#include <QMainWindow>
#include "counter.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();
    Counter counter;

private:
    Ui::Calculator *ui;

public slots:
    void numberPressed(int number);
    void signPressed(int sign);
    void equalPressed();
    void pointPressed();
};


