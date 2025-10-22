#include <QApplication>
#include <QMainWindow>
#include "ui_main_window.h"

class MainWindow: public QMainWindow {
	//Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr): QMainWindow(parent) {
		ui.setupUi(this);
	}
private:
	Ui::MainWindow ui;
};

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	MainWindow w;

	w.show();

	return app.exec();
}
		
