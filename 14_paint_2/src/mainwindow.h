#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
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

	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);

	virtual void paintEvent(QPaintEvent* event);
	
	virtual void resizeEvent(QResizeEvent* event);

private:
	Ui::MainWindow* ui;

	QImage image;

	bool drawing;

	QPoint lastPoint;

	int brushSize;
	QColor brushColor;

private slots:
	void on_action2px_triggered();
	void on_action5px_triggered();
	void on_action10px_triggered();

	void on_actionBlack_triggered();
	void on_actionWhite_triggered();
	void on_actionRed_triggered();
	void on_actionGreen_triggered();
	void on_actionBlue_triggered();

	void on_actionClear_triggered();
	void on_actionSave_triggered();
};

#endif
