#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
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

	bool connectedToHost;
	QTcpSocket* socket;

	void printMessage(QString message);

private slots:
	void on_connectButton_clicked();
	void socketConnected();
	void socketDisconnected();
	void socketReadyRead();

	void on_sendButton_clicked();

};

#endif
