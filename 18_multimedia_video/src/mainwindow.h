#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QTime>
#include <QVideoWidget>

#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
	Q_OBJECT
private:
	Ui::MainWindow *ui;
	QMediaPlayer *player;

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow() {}

private slots:
	void stateChanged(QMediaPlayer::State state);
	void positionChanged(qint64 position);

	void on_playButton_clicked();
	void on_pauseButton_clicked();
	void on_stopButton_clicked();

	void on_volume_sliderMoved(int position);
	void on_progressbar_sliderMoved(int position);

	void on_actionOpen_File_triggered();

};

#endif
