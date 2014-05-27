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
	if (vector.at(index)->text() == "O" || vector.at(index)->text() == "X")
		return;
	if (tictactoe->returnTurn() == 0)
		vector.at(index)->setText("O");
	else
		vector.at(index)->setText("X");
	tictactoe->setValue(index / currentSize, index % currentSize);
	if (tictactoe->DoesPlayerWins())
		showWinner();
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

void MainWindow::showWinner()
{
	int **winner = new int *[2];
	winner[0] = new int [valueToWin];
	winner[1] = new int [valueToWin];
	tictactoe->returnWinningCombination(winner);
	 for (int i = 0; i < valueToWin; i++)
	{
		QPalette pal = vector.at(winner[0][i] * currentSize + winner[1][i])->palette();
		pal.setColor(QPalette::Button, Qt::red);
		vector.at(winner[0][i] * currentSize + winner[1][i])->setPalette(pal);
		vector.at(winner[0][i] * currentSize + winner[1][i])->setAutoFillBackground(true);
		vector.at(winner[0][i] * currentSize + winner[1][i])->show();
	}
	for (int i = 0; i < currentSize; i++)
		for (int j = 0; j < currentSize; j++)
		{
			vector.at(i * currentSize + j)->setDisabled(true);
		}
	QMessageBox msgBox;
	if (tictactoe->returnTurn() == 0)
		msgBox.setText("X wins");
	else
		msgBox.setText("O wins");
	msgBox.exec();
}
