#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QDialog(parent)
{
	nextButton = new QPushButton(tr("next"));
	nextButton->setDisabled(true);
	connect(nextButton, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));

	prevButton = new QPushButton(tr("prev"));
	connect(prevButton, SIGNAL(clicked()), this, SLOT(prevButtonClicked()));
	prevButton->setDisabled(true);

	plusButton = new QPushButton(tr("+"));
	connect(plusButton, SIGNAL(clicked()), this, SLOT(plusButtonClicked()));
	plusButton->setDisabled(true);

	minusButton = new QPushButton(tr("-"));
	connect(minusButton, SIGNAL(clicked()), this, SLOT(minusButtonClicked()));
	minusButton->setDisabled(true);

	tooOldButton = new QPushButton(tr("[:|||:]"));
	connect(tooOldButton, SIGNAL(clicked()), this, SLOT(toOldButtonClicked()));
	tooOldButton->setDisabled(true);

	gotoButton = new QPushButton(tr("Go to this quote"));
	connect(gotoButton, SIGNAL(clicked()), this, SLOT(gotoButtonClicked()));
	gotoButton->setDisabled(true);

	loadButton = new QPushButton(tr("load"));
	connect(loadButton, SIGNAL(clicked()), this, SLOT(loadButtonClicked()));

	NumberOfCurrentQuote = new QLineEdit;
	//NumberOfCurrentQuote->setDisabled(true);

	currentRating = new QLineEdit;
	currentRating->setDisabled(true);

	currentQuote = new QTextEdit;
	currentQuote->setDisabled(true);

	label1 = new QLabel;
	label2 = new QLabel;

	label1->setText("rating");
	label2->setText("number of quote");

	setWindowTitle(tr("Bash.im"));

	QHBoxLayout *buttonLayout1 = new QHBoxLayout;
	buttonLayout1->addWidget(minusButton);
	buttonLayout1->addWidget(tooOldButton);
	buttonLayout1->addWidget(plusButton);
	buttonLayout1->addWidget(label1);
	buttonLayout1->addWidget(currentRating);

	QHBoxLayout *buttonLayout2 = new QHBoxLayout;
	buttonLayout2->addWidget(loadButton);
	buttonLayout2->addWidget(prevButton);
	buttonLayout2->addWidget(nextButton);

	QHBoxLayout *buttonLayout3 = new QHBoxLayout;
	buttonLayout3->addWidget(label2);
	buttonLayout3->addWidget(NumberOfCurrentQuote);
	buttonLayout3->addWidget(gotoButton);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(buttonLayout1);
	mainLayout->addLayout(buttonLayout2);
	mainLayout->addWidget(currentQuote);
	mainLayout->addLayout(buttonLayout3);

	setLayout(mainLayout);
}

void MainWindow::showQuote()
{
	showCurrentQuote();
}

void MainWindow::showCurrentQuote()
{
	QWebElement rating = webpage->page()->mainFrame()->findFirstElement("span[class=rating]");
	QWebElement text = webpage->page()->mainFrame()->findFirstElement("div[class=text]");
	currentRating->setText(QString(rating.toPlainText()));
	currentQuote->setText(QString(text.toPlainText()));
	NumberOfCurrentQuote->setText(QString::number(currentID));
	disableButtons(false);
}

void MainWindow::showFirstQuote()
{
	QWebElement firstQuoteID = webpage->page()->mainFrame()->findFirstElement("a[class=id]");
	maxID = (firstQuoteID.toPlainText().mid(1)).toInt();
	currentID = maxID;
	showCurrentQuote();
}

void MainWindow::loadButtonClicked()
{
	currentQuote->setText("Downloading webpage...");
	webpage = new QWebView;
	webpage->load(QUrl("http://bash.im"));
	connect(webpage, SIGNAL(loadFinished(bool)), this, SLOT(showFirstQuote()));
}

void MainWindow::loadNewPage()
{
	currentQuote->setText("Downloading webpage...");
	disableButtons(true);
	delete webpage;
	webpage = new QWebView;
	webpage->load(QUrl("http://bash.im/quote/" + QString::number(currentID)));
	connect(webpage, SIGNAL(loadFinished(bool)), this, SLOT(showQuote()));
	disableButtons(false);
}

void MainWindow::nextButtonClicked()
{
	if (currentID - 1 < 1)
	{
		currentQuote->setText("Previous quote was the first one.");
		return;
	}
		currentID--;
		loadNewPage();
}

void MainWindow::prevButtonClicked()
{
	if (currentID + 1 > maxID)
	{
		currentQuote->setText("Previous quote was the last one.");
		return;
	}
		currentID++;
		loadNewPage();
}

void MainWindow::plusButtonClicked()
{
	QNetworkRequest postRequest(QUrl("http://bash.im/quote/" + QString::number(currentID)));
	postRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	QNetworkAccessManager *postManager = new QNetworkAccessManager(this);
	postManager->post(postRequest, "/rulez");

	loadNewPage();
	delete postManager;
}

void MainWindow::minusButtonClicked()
{
	QNetworkRequest postRequest(QUrl("http://bash.im/quote/" + QString::number(currentID)));
	postRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	QNetworkAccessManager *postManager = new QNetworkAccessManager(this);
	postManager->post(postRequest, "/sux");

	loadNewPage();
	delete postManager;
}

void MainWindow::tooOldButtonClicked()
{
	QNetworkRequest postRequest(QUrl("http://bash.im/quote/" + QString::number(currentID)));
	postRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	QNetworkAccessManager *postManager = new QNetworkAccessManager(this);
	postManager->post(postRequest, "/bayan");

	loadNewPage();
	delete postManager;
}

void MainWindow::gotoButtonClicked()
{
	int newID = NumberOfCurrentQuote->text().toInt();
	if (newID < 1 || newID > maxID)
	{
		currentQuote->setText("incorrect number of quote");
		return;
	}

	currentID = newID;
	loadNewPage();

}

void MainWindow::disableButtons(bool status)
{
	nextButton->setDisabled(status);
	prevButton->setDisabled(status);
	plusButton->setDisabled(status);
	minusButton->setDisabled(status);
	tooOldButton->setDisabled(status);
	loadButton->setDisabled(status);
	gotoButton->setDisabled(status);
}
