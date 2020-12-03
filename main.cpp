#include "UI/mainwindow.h"

#include <QApplication>
#include <utility>
#include <screenshots/SaveScreenshot.h>

int main(int argc, char *argv[]) {
    auto *screenshot = new SaveScreenshot();

	FaceRecognizer::getRecognizer().onPrediction([screenshot](Result r) {
        screenshot->run(std::move(r));
	});
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
