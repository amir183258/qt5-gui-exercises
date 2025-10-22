#include <QCoreApplication>
#include <QMainWindow>
#include "./mainwindow.h"
#include "./ui_mainwindow.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	MainWindow window;
	window.show();

	return app.exec();
}
