#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->operation->addItem("-");
    ui->operation->addItem("+");
    ui->operation->addItem(":");
    ui->operation->addItem("*");
    connect(ui->first_button, SIGNAL(valueChanged(int)), this, SLOT(recalculate()));
    connect(ui->secondbutton, SIGNAL(valueChanged(int)), this, SLOT(recalculate()));
    connect(ui->operation, SIGNAL(currentIndexChanged(QString)), this, SLOT(recalculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recalculate()
{
    int firstNumber = ui->first_button->value();
    int secondNumber = ui->secondbutton->value();
    char operation = ui->operation->currentText().toStdString()[0];

    if (operation == ':' && secondNumber == 0)
        ui->answer->setText("error");
    else
        ui->answer->setText(QString::number(calculator.doOperation(firstNumber, secondNumber, operation)));
}
