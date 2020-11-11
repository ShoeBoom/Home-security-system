#ifndef CS3307_FACIAL_REC_FACERECOGNIZER_H_
#define CS3307_FACIAL_REC_FACERECOGNIZER_H_

#include "database/Database.h"
#include "database/KnownPerson.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <vector>

class FaceRecognizer {
 private:
  Database peopleDatabase;
  cv::Ptr<cv::face::LBPHFaceRecognizer> model;

 public:
  FaceRecognizer(std::vector<KnownPerson> known);
  ~FaceRecognizer();
  void addPerson(KnownPerson known);
};

#endif //CS3307_FACIAL_REC_FACERECOGNIZER_H_
