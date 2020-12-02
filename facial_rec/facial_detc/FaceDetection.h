//
// Created by shubh on 2020-12-02.
//

#ifndef CS3307_FACIAL_REC_FACIAL_DETC_FACEDETECTION_H_
#define CS3307_FACIAL_REC_FACIAL_DETC_FACEDETECTION_H_

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

struct Data {
  int number_of_faces;
  std::vector<cv::Rect> faces;
  double first_person_distance;
};

class FaceDetection {
 public:
  virtual ~FaceDetection();
  static FaceDetection &getDetector() {
	  static FaceDetection Detector;
	  return Detector;
  }
  Data detectWithEyeDistance(cv::Mat image);
  Data detectWithoutEyeDistance(cv::Mat image);

 private:
  FaceDetection();
  cv::CascadeClassifier face_cascade;
  cv::CascadeClassifier eyes_cascade;
};

#endif //CS3307_FACIAL_REC_FACIAL_DETC_FACEDETECTION_H_
