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
#include "QLayout"
#include "QDialog"
#include "QtWebKit"
#include "QWebView"
#include "QWebFrame"
#include "QComboBox"
#include "QDebug"
#include "QMessageBox"
#include "QListWidget"



class MainWindow : public QDialog
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		void createLoginWindow();
		void clearWindow(QLayout *layout);
		bool isFolder();
	private slots:
		void loginEntered();
		void createRepoWindow();
		void createFolderWindow();
		void createFileWindow();
		void repoChosen();
		void fileChosen();
		void backToLogin();
		void backToRepos();
		void backToFolder();
		void sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist);

	private:
		QLabel *warningLabel;
		QLineEdit *loginEdit;
		QPushButton *back;
		QLabel *loading;
		QLabel *nameOfBox1;
		QTextEdit *text;
		int folderInFolder;
		QPushButton *next;

		QListWidget *files;
		QString address;
		QString repoName;
		QString loginName;
		QWebView *page;
		QVBoxLayout *mainLayout;
		QWebElementCollection nameOfRepos;
		QWebElementCollection nameOfFiles;
};

#endif // MAINWINDOW_H
