#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "calculator.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:

		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		Calculator calculator;

	private slots:

		/// every function calls after clicking buttons.
		void operationButtonClicked(const QString &operation);
		void numberButtonClicked(const QString &number);
		void clearButtonClicked();
		void equalButtonClicked();
		void pointButtonClicked();

	private:

		Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
