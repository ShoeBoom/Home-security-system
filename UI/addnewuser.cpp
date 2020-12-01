#include "addnewuser.h"
#include "ui_addnewuser.h"
#include "../facial_rec/camera/Camera.h"

#include <QDebug>

AddNewUser::AddNewUser(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddNewUser) {
	ui->setupUi(this);
}

AddNewUser::~AddNewUser() {
	delete ui;
}

void AddNewUser::on_captureButton_clicked() {
	Camera c = Camera::getInstance();
	auto frame = c.captureGrayscale();
	images.push_back(frame);
}

void AddNewUser::on_buttonBox_accepted() {
	KnownPerson person = KnownPerson(ui->firstname->text().toStdString(),
	                                 ui->lastname->text().toStdString(),
	                                 ui->phone->text().toStdString(),
	                                 images);
	FaceRecognizer::getRecognizer().addPerson(person);
	this->close();
}
