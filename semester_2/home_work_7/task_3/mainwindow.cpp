#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->generate, SIGNAL(clicked()), this, SLOT(clearField()));
	newGame();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::createButtons()
{
	mapper = new QSignalMapper(this);
	for (int i = 0; i < currentSize; i++)
		for (int j = 0; j < currentSize; j++)
		{
			QPushButton *button = new QPushButton;
			button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			button->setText(" ");
			ui->buttonGrid->addWidget(button, i, j);
			vector.append(button);
			connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
			mapper->setMapping(button, (i * currentSize + j));
		}

	connect(mapper, SIGNAL(mapped(int)), this, SLOT(buttonClicked(int)));
}

void MainWindow::buttonClicked(int index)
{
	if (tictactoe->returnTurn() == 0)
		vector.at(index)->setText("O");
	else
		vector.at(index)->setText("X");
	tictactoe->setValue(index / currentSize, index % currentSize);
	if (tictactoe->DoesPlayerWins())
	{
		QMessageBox msgBox;
		if (tictactoe->returnTurn() == 0)
			msgBox.setText("X wins");
		else
			msgBox.setText("O wins");
		msgBox.exec();
	}
}

void MainWindow::clearField()
{
	for (int i = 0; i < currentSize; i++)
		for (int j = 0; j < currentSize; j++)
			delete ui->buttonGrid->itemAtPosition(i, j)->widget();
	delete tictactoe;
	vector.clear();
	delete mapper;
	newGame();
}

void MainWindow::newGame()
{
	currentSize = ui->sizeSpin->value();
	valueToWin = ui->valueSpin->value();
	tictactoe = new TicTacToe(currentSize, valueToWin);
	createButtons();
}
