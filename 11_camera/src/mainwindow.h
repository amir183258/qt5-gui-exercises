#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget* parent = nullptr);

	~MainWindow() {}

private:
	Ui::MainWindow* ui;
	QCamera* camera;
	QCameraViewfinder* viewfinder;
	QCameraImageCapture* imageCapture;
	QMediaRecorder* recorder;

	bool connected;
	bool recording;

	void connectCamera();

private slots:
	void on_connectButton_clicked();
	void on_captureButton_clicked();
	void on_recordButton_clicked();

};

#endif
