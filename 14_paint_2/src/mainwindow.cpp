#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QtSvg/QSvgGenerator>
#include <QFileDialog>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent):
QMainWindow (parent), ui (new Ui::MainWindow) {
	ui->setupUi(this);

	image = QImage(this->size(), QImage::Format_RGB32);
	image.fill(Qt::white);

	drawing = false;
	brushColor = Qt::black;
	brushSize = 2;
}

void MainWindow::paintEvent(QPaintEvent* event) {
	QPainter canvasePainter(this);
	canvasPainter.drawImage(this->rect(), image, image.rect());
}

