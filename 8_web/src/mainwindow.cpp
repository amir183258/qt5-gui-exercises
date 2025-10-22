#include <QMainWindow>
#include <QWebEngineView>
#include <QDebug>
#include <QResource>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	qDebug() << "valid?" << QResource(":/html/test.html").isValid();

	webview = new QWebEngineView(this);
	webview->load(QUrl("qrc:///html/test.html"));

	ui->verticalLayout->addWidget(webview);

	connect(webview, &QWebEngineView::loadProgress, this, &MainWindow::webviewLoading);
}

// slots
void MainWindow::on_backButton_clicked() {
	webview->back();
}

void MainWindow::on_forwardButton_clicked() {
	webview->forward();
}

void MainWindow::on_refreshButton_clicked() {
	webview->reload();
}

void MainWindow::on_goButton_clicked() {
	loadPage();
}

void MainWindow::loadPage() {
	QString url = ui->addressInput->text();
	if (!url.startsWith("http://") && !url.startsWith("https://"))
		url = "http://" + url;
	ui->addressInput->setText(url);

	webview->load(QUrl(url));
}

void MainWindow::on_addressInput_returnPressed() {
	loadPage();
}

void MainWindow::webviewLoading(int progress) {
	ui->progressBar->setValue(progress);
	qDebug() << progress;
}

void MainWindow::webviewLoaded() {
	ui->addressInput->setText(webview->url().toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}
