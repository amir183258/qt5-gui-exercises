#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QPixmap>
#include <QPainter>

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

	QPixmap* imageBuffer;
	QPixmap imagePixmap;
	
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow() {}

	void resizeImage();
	void paintEvent(QPaintEvent *event);

private slots:
	void on_actionOpen_triggered();

};

#endif
