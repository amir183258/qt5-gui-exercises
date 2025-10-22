// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ui_mainwindow.h"
#include "./profilebox.h"
#include "./profileline.h"

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

    void updateLines();

    void keyReleaseEvent(QKeyEvent* event);

    ~MainWindow();

private:
	Ui::MainWindow *ui;
	QGraphicsScene* scene;
	QList<profileLine*> lines;

private slots:
	void selectionChanged();
	
	void on_addButton_clicked();
};

#endif // MAINWINDOW_H

