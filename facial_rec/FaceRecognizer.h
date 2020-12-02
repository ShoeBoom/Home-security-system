#ifndef CS3307_FACIAL_REC_FACERECOGNIZER_H_
#define CS3307_FACIAL_REC_FACERECOGNIZER_H_

#include "database/Database.h"
#include "database/KnownPerson.h"
#include "facial_detc/FaceDetection.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <vector>
#include <functional>

struct Result {
  int personID;
  double confidence;
  double distance;
};

class FaceRecognizer {
 private:
  FaceRecognizer();
  cv::Ptr<cv::face::LBPHFaceRecognizer> model = cv::face::LBPHFaceRecognizer::create();
  std::vector<std::function<void(Result)>> callbacks;
  void callAll(Result result);

 public:
  static FaceRecognizer &getRecognizer() {
	  static FaceRecognizer recog;
	  return recog;
  }
  ~FaceRecognizer();
  void addPerson(KnownPerson person);
  Result predict(const cv::Mat &image);
  Result predictCamera();
  bool isEmpty();
  void onPrediction(const std::function<void(Result)> &func);
  void retrain();
  static KnownPerson getPersonByID(int i);
};

#endif //CS3307_FACIAL_REC_FACERECOGNIZER_H_
