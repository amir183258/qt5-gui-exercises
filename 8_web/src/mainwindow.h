// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
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
    void loadPage();

    ~MainWindow();

private:
	Ui::MainWindow *ui;
	QWebEngineView* webview;

private slots:
	void on_backButton_clicked();
	void on_forwardButton_clicked();
	void on_refreshButton_clicked();
	void on_goButton_clicked();

	void on_addressInput_returnPressed();

	void webviewLoading(int progress);
	void webviewLoaded();

};

#endif // MAINWINDOW_H

