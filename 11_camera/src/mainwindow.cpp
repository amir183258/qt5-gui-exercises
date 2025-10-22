#include <QDebug>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QUrl>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent):
QMainWindow (parent), ui (new Ui::MainWindow) {
	ui->setupUi(this);

	connected = false;
	camera = new QCamera();

	qDebug() << "Number of cameras found: " <<
		QCameraInfo::availableCameras().count();

	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

	foreach (const QCameraInfo& cameraInfo, cameras) {
		qDebug() << "Camera info:" << cameraInfo.deviceName() <<
			cameraInfo.description() << cameraInfo.position();

		ui->deviceSelection->addItem(cameraInfo.description());
	}
}

void MainWindow::on_connectButton_clicked() {
	if (!connected)
		connectCamera();
	else {
		camera->stop();
		viewfinder->deleteLater();
		ui->connectButton->setText("Connect");
		connected = false;
	}
}

void MainWindow::connectCamera() {
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	foreach (const QCameraInfo& cameraInfo, cameras) {
		qDebug() << cameraInfo.description() << ui->deviceSelection->currentText();

		if (cameraInfo.description() == ui->deviceSelection->currentText()) {
			camera = new QCamera(cameraInfo);
			viewfinder = new QCameraViewfinder(this);
			camera->setViewfinder(viewfinder);
			ui->webcamLayout->addWidget(viewfinder);

			connected = true;
			ui->connectButton->setText("Disconnect");

			camera->start();

			return;
		}
	}
}

void MainWindow::on_captureButton_clicked() {
	if (connected) {
		imageCapture = new QCameraImageCapture (camera);
		camera->setCaptureMode(QCamera::CaptureStillImage);
		camera->searchAndLock();
		imageCapture->capture(qApp->applicationDirPath());
		camera->unlock();
	}
}

void MainWindow::on_recordButton_clicked() {
	if (connected)
		if (!recording) {
			recorder = new QMediaRecorder (camera);
			camera->setCaptureMode(QCamera::CaptureVideo);

			QString fileName = qApp->applicationDirPath() + "/recording.mp4";
			recorder->setOutputLocation(QUrl::fromLocalFile(fileName));

			recorder->record();
			recording = true;
		}
		else {
			recorder->stop();
			recording = false;
		}
}
