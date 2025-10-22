#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

void MainWindow::paintEvent(QPaintEvent *event) {
	if (canDraw) {
		QPainter painter(this);
		paintImage(painter, ui->productImage->pos().x(), ui->productImage->pos().y());
	}
}

void MainWindow::paintImage(QPainter& painter, int x, int y) {
	if (pix) {
		painter.setClipRect(x, y, 150, 150);
		painter.fillRect(QRect(x, y, 150, 150), Qt::SolidPattern);
		painter.drawPixmap(x - drawPos.x(), y - drawPos.y(),
				drawSize.width(), drawSize.height(), *pix);
	}

}

void MainWindow::saveImage(QString fileName) {
	if (fileName.isEmpty())
		return;

	QPainter painter;
	QImage save_image(150, 150, QImage::Format_RGB16);
	save_image.fill(Qt::white);

	painter.begin(&save_image);
	paintImage(painter, 0, 0);
	painter.end();

	save_image.save(fileName);
	QMessageBox::information(this, "Success", "Image has been successfully saved!");
}

// signals
void MainWindow::on_scaleSlider_valueChanged(int value) {
	drawSize = imageSize * value / 100;

	update();
}

void MainWindow::on_leftSlider_valueChanged(int value) {
	drawPos.setX(value * drawSize.width() / 100 * 0.5);

	update();
}

void MainWindow::on_topSlider_valueChanged(int value) {
	drawPos.setY(value * drawSize.height() / 100 * 0.5);

	update();
}

//slots
void MainWindow::on_browseButton_clicked() {
	QString fileName = QFileDialog::getOpenFileName(
			this,
			tr("Open Image"),
			QDir::currentPath(),
			tr("Image Files (*.jpg *.jpeg)"));

	if (!fileName.isEmpty()) {
		QPixmap* newPix = new QPixmap(fileName);

		if (!newPix->isNull()) {
			if (newPix->width() < 150 || newPix->height() < 150) {
				QMessageBox::warning(this, tr("Invalid Size"),
						tr("Image size too small. Please use an image"
							" larger than 150x150."));
				return;
			}
			pix = newPix;
			imageSize = pix->size();
			drawSize = pix->size();

			canDraw = true;
			update();
		}
		else {
			canDraw = false;

			QMessageBox::warning(this, tr("Invalid Image"),
					tr("Invalid or corrupted file. Please"
						" try again with another image file."));
		}
	}
}

void MainWindow::on_saveButton_clicked() {
	if (canDraw) 
		if (pix)
			saveImage(QCoreApplication::applicationDirPath() + "/image.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}
