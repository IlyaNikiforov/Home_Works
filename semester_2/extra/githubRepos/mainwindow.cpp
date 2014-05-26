#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QDialog(parent)
{
	folderInFolder = 0;
	page = new QWebView;
	connect(page->page()->networkAccessManager(),
			SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )),
			this,
			SLOT(sslErrorHandler(QNetworkReply*, const QList<QSslError> & )));

	createLoginWindow();
}

void MainWindow::createLoginWindow()
{
	warningLabel = new QLabel(tr("Enter login:"));
	loginEdit = new QLineEdit;
	next = new QPushButton(tr("->"));
	loading = new QLabel;
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(loginEdit);
	layout->addWidget(next);
	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(warningLabel);
	mainLayout->addLayout(layout);
	mainLayout->addWidget(loading);
	setLayout(mainLayout);
	connect(next, SIGNAL(clicked()), this, SLOT(loginEntered()));
}

void MainWindow::loginEntered()
{
	loginName = loginEdit->text();
	page->load(QUrl("https://github.com/" + loginName + "?tab=repositories"));
	loading->setText("Loading...");
	connect(page, SIGNAL(loadFinished(bool)), this, SLOT(createRepoWindow()));
}

void MainWindow::createRepoWindow()
{
	QString title = page->page()->mainFrame()->title();
	if (title[0] == 'P' && title[1] == 'a' && title[2] == 'g' && title[3] == 'e' && title[5] == 'n' && title[6] == 'o')
	{
		QMessageBox msgBox;
		msgBox.setText("The login you entered does not exist on github");
		msgBox.exec();
		return;
	}
	clearWindow(mainLayout);
	warningLabel = new QLabel;
	warningLabel->setText(loginName);
	nameOfBox1 = new QLabel(tr("Repos:"));
	files = new QListWidget;
	back = new QPushButton(tr("back"));
	connect(back, SIGNAL(clicked()), this, SLOT(backToLogin()));
	loading = new QLabel;
	QHBoxLayout *layout2 = new QHBoxLayout;
	layout2->addWidget(back);
	layout2->addWidget(loading);
	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(warningLabel);
	mainLayout->addWidget(nameOfBox1);
	mainLayout->addWidget(files);
	mainLayout->addLayout(layout2);
	setLayout(mainLayout);
	connect(files, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(repoChosen()));
	nameOfRepos = page->page()->mainFrame()->findAllElements("h3[class=repolist-name]");
	for (int i = 0; i < nameOfRepos.count(); i++)
	{
		files->addItem(nameOfRepos.at(i).toPlainText());
	}
}

void MainWindow::backToLogin()
{
	delete page;
	page = new QWebView;
	loading->setText("Loading...");
	clearWindow(mainLayout);
	createLoginWindow();
}

void MainWindow::repoChosen()
{
	repoName = files->currentItem()->text();
	address = "/" + loginName + "/" + repoName;
	delete page;
	page = new QWebView;
	loading->setText("Loading...");
	page->load(QUrl("https://github.com" + address));
	connect(page, SIGNAL(loadFinished(bool)), this, SLOT(createFolderWindow()));
}

void MainWindow::createFolderWindow()
{
	loading->clear();
	warningLabel->setText(address);
	nameOfBox1->setText("Files:");
	files->clear();
	files->disconnect();
	back->disconnect();
	connect(files, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(fileChosen()));
	connect(back, SIGNAL(clicked()), this, SLOT(backToRepos()));
	nameOfFiles = page->page()->mainFrame()->findAllElements("td[class=content]");
	for (int i = 0; i < nameOfFiles.count(); i++)
		files->addItem(nameOfFiles.at(i).toPlainText());
}

void MainWindow::backToRepos()
{
	if (folderInFolder > 1)
	{
		int temp = 0;
		for (int i = 0; i < address.length(); i++)
			if (address[i] == '/')
				temp = i;
		QString newAddress;
		for (int i = 0; i < temp; i++)
			newAddress[i] = address[i];
		address = newAddress;
	}

	else if (folderInFolder == 1)
		address = "/" + loginName + "/" + repoName;

	else
	{
		backToLogin();
		return;
	}

	delete page;
	page = new QWebView;
	//if (folderInFolder > 0)
		folderInFolder--;
	loading->setText("Loading...");
	page->load(QUrl("https://github.com" + address));
	connect(page, SIGNAL(loadFinished(bool)), this, SLOT(createFolderWindow()));
}

void MainWindow::fileChosen()
{
	address = nameOfFiles[files->currentRow()].findFirst("a").attribute("href");
	delete page;
	page = new QWebView;
	loading->setText("Loading...");
	page->load(QUrl("https://github.com" + address));
	folderInFolder++;
	if (isFolder())
		connect(page, SIGNAL(loadFinished(bool)), this, SLOT(createFolderWindow()));
	else
		connect(page, SIGNAL(loadFinished(bool)), this, SLOT(createFileWindow()));
}

bool MainWindow::isFolder()
{
	QString addressOfFile = nameOfFiles[files->currentRow()].findFirst("a").attribute("href");
	int count = 0;
	int i = 0;
	while (count != 3)
	{
		if (addressOfFile[i] == '/')
			count++;
		i++;
	}
	if (addressOfFile[i] == 't')
		return true;
	return false;
}

void MainWindow::createFileWindow()
{
	clearWindow(mainLayout);
	warningLabel = new QLabel;
	warningLabel->setText(address);
	back = new QPushButton(tr("back"));
	text = new QTextEdit;
	connect(back, SIGNAL(clicked()), this, SLOT(backToFolder()));
	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(warningLabel);
	mainLayout->addWidget(back);
	mainLayout->addWidget(text);
	setLayout(mainLayout);
	text->setText(page->page()->mainFrame()->findFirstElement("td[class=blob-line-code]").toPlainText());
}

void MainWindow::backToFolder()
{
	clearWindow(mainLayout);
	warningLabel = new QLabel;
	nameOfBox1 = new QLabel(tr("Files:"));
	back = new QPushButton(tr("back"));
	loading = new QLabel;
	files = new QListWidget;
	QHBoxLayout *layout2 = new QHBoxLayout;
	layout2->addWidget(back);
	layout2->addWidget(loading);
	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(warningLabel);
	mainLayout->addWidget(nameOfBox1);
	mainLayout->addWidget(files);
	mainLayout->addLayout(layout2);
	setLayout(mainLayout);
	backToRepos();
}

void MainWindow::clearWindow(QLayout *layout)
{
	if (layout == nullptr)
		return;

	QLayoutItem *object;
	while (object = layout->takeAt(0))
	{
		if (object->layout() != nullptr)
			clearWindow(object->layout());
		else if (object->widget() != nullptr)
			delete object->widget();
	}
	delete layout;
}

void MainWindow::sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist)
{
  #if DEBUG_ENABLED
  qDebug() << "---frmBuyIt::sslErrorHandler: ";
  // show list of all ssl errors
  foreach (QSslError err, errlist)
	qDebug() << "ssl error: " << err;
  #endif

  qnr->ignoreSslErrors();
}

