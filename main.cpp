/**
main.cpp
@brief: Runs the facial recognition security system with a user interface.
@author: Group53
**/

#include "UI/mainwindow.h"
#include "FaceRecognizer.h"
#include "twilio.h"
#include <QApplication>
#include <utility>
#include <screenshots/SaveScreenshot.h>

int main(int argc, char *argv[]) {
    //pointer to save a screenshot
    auto *screenshot = new SaveScreenshot();
    
    //facial recognition
	FaceRecognizer::getRecognizer().onPrediction([screenshot](Result r) {
        screenshot->run(std::move(r));
	});
    //User interface
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();

    
}
