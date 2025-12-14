#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent):
QMainWindow (parent), ui (new Ui::MainWindow) {
	ui->setupUi(this);
	
	imageBuffer = nullptr;
}

void MainWindow::resizeImage() {
    if (imageBuffer != nullptr) {
        // Resize the image according to the display area
        QSize size = ui->imageDisplay->size();
        QPixmap pixmap = imageBuffer->scaled(size, Qt::KeepAspectRatio);

        // Adjust the position of the image to the center
        imagePixmap = pixmap;  // Save the scaled pixmap for painting
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  // Optional: For smoother rendering

    if (imageBuffer != nullptr) {
        QSize size = ui->imageDisplay->size();
        QPixmap pixmap = imagePixmap;  // Use the saved pixmap

        // Adjust the position of the image to the center
        QRect rect = ui->imageDisplay->rect();
        rect.setX((this->size().width() - pixmap.width()) / 2);
        rect.setY((this->size().height() - pixmap.height()) / 2);

        painter.drawPixmap(rect, pixmap);
    }
}

void MainWindow::on_actionOpen_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image File",
                         qApp->applicationDirPath(), "JPG (*.jpg *.jpeg);;PNG (*.png)");

    if (!fileName.isEmpty()) {
        imageBuffer = new QPixmap(fileName);  // Load image
        resizeImage();  // Prepare the image for resizing and drawing
        update();  // Trigger repaint to redraw the image
    }
}

