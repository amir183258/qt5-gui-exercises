// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);
    void paintImage(QPainter& painter, int x, int y);
    void saveImage(QString fileName);

private:

	Ui::MainWindow *ui;
	bool canDraw;
	QPixmap* pix = nullptr;
	QSize imageSize;
	QSize drawSize;
	QPoint drawPos;

private slots:
	void on_browseButton_clicked();
	void on_saveButton_clicked();

	void on_scaleSlider_valueChanged(int value); // TODO correct signals
	void on_leftSlider_valueChanged(int value);
	void on_topSlider_valueChanged(int value);
};

#endif // MAINWINDOW_H

