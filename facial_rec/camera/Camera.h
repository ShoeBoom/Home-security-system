#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#ifndef CS3307_FACIAL_REC_CAMERA_CAMERA_H_
#define CS3307_FACIAL_REC_CAMERA_CAMERA_H_

class Camera {
 public:
  void operator=(const Camera &) = delete;
  static Camera &getInstance() {
	  static Camera _instance;
	  return _instance;
  }
  cv::Mat capture();
  cv::Mat captureGrayscale();
  cv::Mat captureRGB();
 private:
  Camera();
  cv::VideoCapture cap;

};

#endif //CS3307_FACIAL_REC_CAMERA_CAMERA_H_
