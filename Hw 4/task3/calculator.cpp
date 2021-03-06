#include "calculator.h"
#include "ui_calculator.h"
#include "qsignalmapper.h"
#include "counter.h"


Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    isCalculatorClear = true;

    QSignalMapper* numberMapper = new QSignalMapper(0);
    connect(ui->zero, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->zero, 0);
    connect(ui->one, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->one, 1);
    connect(ui->two, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->two, 2);
    connect(ui->three, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->three, 3);
    connect(ui->four, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->four, 4);
    connect(ui->five, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->five, 5);
    connect(ui->six, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->six, 6);
    connect(ui->seven, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->seven, 7);
    connect(ui->eight, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->eight, 8);
    connect(ui->nine, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(ui->nine, 9);

    connect(numberMapper, SIGNAL(mapped(int)), this, SLOT(numberPressed(int)));

    QSignalMapper* operationMapper = new QSignalMapper(0);
    connect(ui->plus, SIGNAL(clicked()), operationMapper, SLOT(map()));
    operationMapper->setMapping(ui->plus, 0);
    connect(ui->minus, SIGNAL(clicked()), operationMapper, SLOT(map()));
    operationMapper->setMapping(ui->minus, 1);
    connect(ui->multiplication, SIGNAL(clicked()), operationMapper, SLOT(map()));
    operationMapper->setMapping(ui->multiplication, 2);
    connect(ui->division, SIGNAL(clicked()), operationMapper, SLOT(map()));
    operationMapper->setMapping(ui->division, 3);

    connect(operationMapper, SIGNAL(mapped(int)), this, SLOT(signPressed(int)));

    connect(ui->equal, SIGNAL(clicked()), this, SLOT(equalPressed()));
    connect(ui->point, SIGNAL(clicked()), this, SLOT(pointPressed()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearCalculator()));
}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::signPressed(int sign)
{
    if (!isCalculatorClear)
        equalPressed();
    counter.addSign(sign);
    isCalculatorClear = false;
    return;
}

void Calculator::numberPressed(int number)
{
    ui->result->setText(counter.addNumber(number));
    return;
}

void Calculator::pointPressed()
{
    ui->result->setText(counter.addPoint());
    return;
}

void Calculator::equalPressed()
{
    ui->result->setText(counter.calculate());
    isCalculatorClear = false;
    return;
}

void Calculator::clearCalculator()
{
    counter.clearCounter();
    isCalculatorClear = true;
    ui->result->setText("");
    return;
}
