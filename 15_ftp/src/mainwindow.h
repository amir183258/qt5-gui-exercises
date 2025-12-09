#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMessageBox>

#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
	Q_OBJECT
private:
	Ui::MainWindow* ui;
	QNetworkAccessManager* manager;

	QString ftpAddress;
	int ftpPort;
	QString username;
	QString password;

	QNetworkReply* downloadFileListReply;
	QNetworkReply* uploadFileListReply;

	QNetworkReply* downloadFileReply;
	QNetworkReply* uploadFileReply;

	QStringList fileList;
	QString downloadFileName;
	QString uploadFileName;
	
public:
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow() {}

	void getFileList();

private slots:
	void downloadFileListFinished();
	
	// upload files
	void on_openButton_clicked();
	void on_uploadButton_clicked();

	void uploadFileProgress(qint64 bytesSent, qint64 bytesTotal);
	void uploadFileFinished();
	void uploadFileListFinished();

	// download files
	void on_setFolderButton_clicked();
	void on_fileList_itemDoubleClicked(QListWidgetItem *item);

	void downloadFileProgress(qint64 byteRecieved, qint64 bytesTotal);
	void downloadFileFinished();
};

#endif
