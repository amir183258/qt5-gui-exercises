#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QPainter>
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
	virtual void paintEvent(QPaintEvent *event);

private:
	Ui::MainWindow* ui;

private slots:

};

#endif
