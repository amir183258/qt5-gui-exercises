#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent):
QMainWindow (parent), ui (new Ui::MainWindow) {
	ui->setupUi(this);

	player = new QMediaPlayer (this);
	player->setVolume(ui->volume->value());

	connect(player, &QMediaPlayer::stateChanged, this, &MainWindow::stateChanged);
	connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
}
