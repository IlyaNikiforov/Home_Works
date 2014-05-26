#pragma once
#include "tictactoe.h"
#include "qvector.h"
#include <QMainWindow>
#include "qlineedit.h"
#include "qpushbutton.h"
#include "qsignalmapper.h"
#include "qmessagebox.h"
#include "qpalette.h"
#include "qcolor.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		void createButtons();
		void newGame();
		void showWinner();
	public slots:
		void buttonClicked(int index);
		void clearField();

	private:
		Ui::MainWindow *ui;
		TicTacToe *tictactoe;
		QVector<QPushButton*> vector;
		QSignalMapper *mapper;
		int currentSize;
		int valueToWin;
};


