#include "UI/mainwindow.h"

#include <QApplication>
#include <utility>
#include "demo/subscriptionExample.h"

int main(int argc, char *argv[]) {
	auto *example = new subscriptionExample();
	FaceRecognizer::getRecognizer().onPrediction([example](Result r) {
	  example->run(std::move(r));
	});
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
