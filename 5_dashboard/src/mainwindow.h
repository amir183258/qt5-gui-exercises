// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

#include <QtCharts>
#include <QChartView>

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

private slots:
    void on_loginButton_clicked();

private:
	QChartView *chartViewBar;
	QChartView *chartViewPie;
	QChartView *chartViewLine;

	Ui::MainWindow *ui;
	QSqlDatabase db;

    // handling charts
    void handle_charts();

protected:
    void resizeEvent(QResizeEvent* event);
};

#endif // MAINWINDOW_H

