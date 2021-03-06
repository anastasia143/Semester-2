#include "mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->firstNumber, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
    connect(ui->secondNumber, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
    connect(ui->sign, SIGNAL(currentIndexChanged(int)), this, SLOT(calculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    int firstNumber = ui->firstNumber->value();
    int secondNumber = ui->secondNumber->value();
    int result = 0;

    switch(ui->sign->currentIndex())
    {
    case 0:
        result = firstNumber + secondNumber;
        break;
    case 1:
        result = firstNumber - secondNumber;
        break;
    case 2:
        result = firstNumber * secondNumber;
        break;
    case 3:
    {
        if (secondNumber == 0)
        {
            ui->result->setText("error");
            return;
        }
        result = firstNumber / secondNumber;
        break;
    }
    }
    ui->result->setText(QString::number(result));
    return;
}
