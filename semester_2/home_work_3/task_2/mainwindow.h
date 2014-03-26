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

private:
	Ui::MainWindow *ui;
	Calculator calculator;

private slots:
	void recalculate();

};

#endif // MAINWINDOW_H
