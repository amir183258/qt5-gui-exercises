#include <QNetworkAccessManager>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent):
QMainWindow (parent), ui (new Ui::MainWindow) {
	ui->setupUi(this);

	manager = new QNetworkAccessManager(this);

	ftpAddress = "ftp://127.0.0.1/shared_folder/";
	ftpPort = 21;
	username = "test";
	password = "183258";

	getFileList();
}

// handling file list
void MainWindow::getFileList() {
	QUrl ftpPath;
	ftpPath.setUrl(ftpAddress + "files.txt");
	ftpPath.setUserName(username);
	ftpPath.setPassword(password); ftpPath.setPort(ftpPort);

	QNetworkRequest request;
	request.setUrl(ftpPath);

	downloadFileListReply = manager->get(request);
	connect(downloadFileListReply, &QNetworkReply::finished, this, &MainWindow::downloadFileListFinished);
}

void MainWindow::downloadFileListFinished() {
	if (downloadFileListReply->error() != QNetworkReply::NoError)
		QMessageBox::warning(this, "Failed", "Failed to load file lsit: " +
				downloadFileListReply->errorString());
	else {
		QByteArray responseData;
		if (downloadFileListReply->isReadable())
			responseData = downloadFileListReply->readAll();

		// Display file list
		ui->fileList->clear();
		fileList = QString(responseData).split(",");

		if (fileList.size() > 0)
			for (int i = 0; i < fileList.size(); ++i)
				if (fileList.at(i) != "")
					ui->fileList->addItem(fileList.at(i));
	}
}

// upload open button slot function
void MainWindow::on_openButton_clicked() {
	QString fileName = QFileDialog::getOpenFileName(this, "Select File", qApp->applicationDirPath());
	ui->uploadFileInput->setText(fileName);
}

// upload button slot function
void MainWindow::on_uploadButton_clicked() {
	QFile* file = new QFile(ui->uploadFileInput->text());
	QFileInfo fileInfo(*file);
	uploadFileName = fileInfo.fileName();

	QUrl ftpPath;
	ftpPath.setUrl(ftpAddress + "share_folder/" + uploadFileName);
	ftpPath.setUserName(username);
	ftpPath.setPassword(password);
	ftpPath.setPort(ftpPort);

	if (file->open(QIODevice::ReadOnly)) {
		ui->uploadProgress->setEnable(true);
		ui->uploadProgress->setValue(0);

		QNetworkRequest request;
		request.setUrl(ftpPath);

		// TODO
		uploadFileReply = manager->put(request, file);
		connect(uploadFileReply


	}
}
