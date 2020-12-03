#include "UI/mainwindow.h"
#include "FaceRecognizer.h"
#include "twilio.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();

    
}
