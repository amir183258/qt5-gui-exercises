#include <QMainWindow>
#include <QDebug>
#include <QResource>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QGeoPositionInfoSource* source = 
		QGeoPositionInfoSource::createDefaultSource(this);

	if (source) {
		qDebug() << "hi";
		connect(source, &QGeoPositionInfoSource::positionUpdated,
				this, &MainWindow::positionUpdated);
		source->startUpdates();
	}
}

void MainWindow::positionUpdated(const QGeoPositionInfo& info) {
	qDebug() << "Position updated:" << info;
}

MainWindow::~MainWindow()
{
    delete ui;
}
