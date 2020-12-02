#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./addnewuser.h"

#include <QTimer>
#include <QDebug>

#include "../facial_rec/camera/Camera.h"
#include "../facial_rec/FaceRecognizer.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	timer = new QTimer(this);
	predictionTimer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &MainWindow::updateImage);
	connect(predictionTimer, &QTimer::timeout, this, &MainWindow::updatePrediction);
	timer->start(10);
	predictionTimer->start(1000);
}

void MainWindow::updateImage() {
	Camera c = Camera::getInstance();
	auto img = c.captureRGB();
	if (!img.empty()) {
		ui->cameraImage->setPixmap(QPixmap::fromImage(QImage(img.data,
		                                                     img.cols,
		                                                     img.rows,
		                                                     img.step,
		                                                     QImage::Format_RGB888)));
	}
}

void MainWindow::updatePrediction() {

	if (!FaceRecognizer::getRecognizer().isEmpty()) {
		Camera c = Camera::getInstance();
		auto img = c.captureGrayscale();
		if (!img.empty()) {
			auto pred = FaceRecognizer::getRecognizer().predict(img);
			int i = pred.personID;
			if (i > -1) {
				auto person = FaceRecognizer::getPersonByID(i);
				ui->prediction->setText(
					QString::fromStdString(person.firstName) + " " + QString::number(pred.confidence) + " "
						+ QString::number(pred.distance));
			} else if (i == -1) {
				ui->prediction->setText("No faces found " + QString::number(pred.confidence));
			} else {
				ui->prediction->setText("Unknown person found");
			}


		}
	} else {
		ui->prediction->setText("No users in database");
	}
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_pushButton_clicked() {

}

void MainWindow::on_actionAdd_New_User_triggered() {
	newuserdialog = new AddNewUser();
	newuserdialog->show();
}
