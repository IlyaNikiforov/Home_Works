#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	/// adding all widgets:
	/// adding text widget
	ui->gridLayout->addWidget(ui->text, 1, 1, 1, 3);

	/// making signal mapper for numbers from 0 to 9
	QSignalMapper *numberMapper = new QSignalMapper;
	connect(numberMapper, SIGNAL(mapped(QString)), this, SLOT(numberButtonClicked(QString)));

	for (int i = 0; i < 10; i++)
	{
		QString *number = new QString;
		number[0] = QString::number(i);
		QPushButton *numberButton = new QPushButton(*number);
		if (i == 0)
			ui->gridLayout->addWidget(numberButton, 5, 1);
		else
			ui->gridLayout->addWidget(numberButton, (i - 1) / 3 + 2, (i - 1) % 3 + 1);
		connect(numberButton, SIGNAL(clicked()), numberMapper, SLOT(map()));
		numberMapper->setMapping(numberButton, *number);
	}

	/// making signal mapper for all operations
	QSignalMapper *operationMapper = new QSignalMapper;
	connect(operationMapper, SIGNAL(mapped(QString)), this, SLOT(operationButtonClicked(QString)));

	for (int i = 0; i < 4; i++)
	{
		QString *operation = new QString;
		if (i == 0)
			operation[0] = '+';
		else if (i == 1)
			operation[0] = '-';
		else if (i == 2)
			operation[0] = '*';
		else
			operation[0] = '/';

		QPushButton *operationButton = new QPushButton(*operation);
		ui->gridLayout->addWidget(operationButton, i + 2, 4);
		connect(operationButton, SIGNAL(clicked()), operationMapper, SLOT(map()));
		operationMapper->setMapping(operationButton, *operation);
	}

	/// adding '=' button
	QPushButton *equalButton = new QPushButton("=");
	ui->gridLayout->addWidget(equalButton, 1, 4);
	connect(equalButton, SIGNAL(clicked()), this, SLOT(equalButtonClicked()));

	/// adding 'C' button
	QPushButton *clearButton = new QPushButton("C");
	ui->gridLayout->addWidget(clearButton, 5, 3);
	connect(clearButton, SIGNAL(clicked()), this, SLOT(clearButtonClicked()));

	/// adding '.' button
	QPushButton *pointButton = new QPushButton(".");
	ui->gridLayout->addWidget(pointButton, 5, 2);
	connect(pointButton, SIGNAL(clicked()), this, SLOT(pointButtonClicked()));
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::numberButtonClicked(const QString &number)
{
	if (calculator.state == none || calculator.state == answer)
		ui->text->setText("");
	ui->text->setText(ui->text->text() + number);
	calculator.addNumber(number.toInt());
}

void MainWindow::pointButtonClicked()
{
	if (calculator.state == firstNumberEnter || calculator.state == secondNumberEnter)
	{
		calculator.addPoint();
		ui->text->setText(ui->text->text() + ".");
	}
}

void MainWindow::operationButtonClicked(const QString &operation)
{
	if (calculator.state == firstNumberPoint || calculator.state == secondNumberPoint
			|| calculator.state == none)
		return;
	if (calculator.state == secondNumberEnter || calculator.state == secondNumberFraction)
	{
		if (calculator.isCorrectOperation())
			ui->text->setText("Error");
		else
			ui->text->setText(QString::number(calculator.calculateAnswer()) + operation);
	}
	else if (calculator.state == operationAdd)
	{
		QString newText = ui->text->text();
		newText[newText.length() - 1] = operation[0];
		ui->text->setText(newText);
	}
	else
		ui->text->setText(ui->text->text() + operation);
	calculator.addOperation(operation);
}

void MainWindow::clearButtonClicked()
{
	calculator.clearAll();
	ui->text->setText("");
}

void MainWindow::equalButtonClicked()
{
	if (calculator.state == secondNumberEnter || calculator.state == secondNumberFraction)
	{
		if (calculator.isCorrectOperation())
		{
			ui->text->setText("Error");
			calculator.clearAll();
			return;
		}
		ui->text->setText(QString::number(calculator.calculateAnswer()));
		calculator.answerToFirstNumber();
		calculator.state = answer;
	}
}
