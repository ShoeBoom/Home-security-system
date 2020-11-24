#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#ifndef CS3307_FACIAL_REC_CAMERA_CAMERA_H_
#define CS3307_FACIAL_REC_CAMERA_CAMERA_H_

class Camera {
 public:
  Camera();
  cv::Mat capture();
  cv::Mat captureGrayscale();
 private:
  cv::VideoCapture cap;
};

#endif //CS3307_FACIAL_REC_CAMERA_CAMERA_H_
