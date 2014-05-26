#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QWidget"
#include "QLineEdit"
#include "QPushButton"
#include "QtNetwork"
#include "QLabel"
#include "QTextEdit"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLineEdit"
#include "QLayout"
#include "QDialog"
#include "QtWebKit"
#include "QWebView"
#include "QWebFrame"


class MainWindow : public QDialog
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		void showCurrentQuote();
		void loadNewPage();
		void disableButtons(bool);
	private slots:
		void showQuote();
		void showFirstQuote();
		void loadButtonClicked();
		void nextButtonClicked();
		void prevButtonClicked();
		void plusButtonClicked();
		void minusButtonClicked();
		void tooOldButtonClicked();
		void gotoButtonClicked();

	private:
		QPushButton *nextButton;
		QPushButton *prevButton;
		QPushButton *plusButton;
		QPushButton *minusButton;
		QPushButton *tooOldButton;
		QPushButton *loadButton;
		QPushButton *gotoButton;
		QLabel *label1;
		QLabel *label2;
		QLineEdit *NumberOfCurrentQuote;
		QLineEdit *currentRating;
		QTextEdit *currentQuote;

		QWebView *webpage;
		int maxID;
		int currentID;
};

#endif // MAINWINDOW_H
