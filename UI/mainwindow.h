#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../facial_rec/camera/Camera.h"
#include "../facial_rec/FaceRecognizer.h"
#include "./addnewuser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_clicked();
  void updateImage();
  void updatePrediction();

  void on_actionAdd_New_User_triggered();

 private:
  QTimer *timer;
  Ui::MainWindow *ui;
  AddNewUser *newuserdialog;

};
#endif // MAINWINDOW_H
