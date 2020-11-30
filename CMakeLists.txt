cmake_minimum_required(VERSION 3.16)
project(cs3307)

set(CMAKE_CXX_STANDARD 20)

set(CURL_LIBRARY "-lcurl")
set(CURL_INCLUDE_DIR)
find_package(CURL REQUIRED)

find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cs3307 main.cpp
        facial_rec/database/Database.cpp facial_rec/database/Database.h
        facial_rec/database/KnownPerson.cpp facial_rec/database/KnownPerson.h
        facial_rec/database/UnknownPerson.cpp facial_rec/database/UnknownPerson.h
        facial_rec/FaceRecognizer.cpp facial_rec/FaceRecognizer.h
        twilio/twilio.cpp twilio/twilio.h twilio/type_conversion.h
        facial_rec/camera/Camera.cpp facial_rec/camera/Camera.h
        facial_rec/face_dec/FaceDetection.cpp facial_rec/face_dec/FaceDetection.h)
target_link_libraries(cs3307 ${OpenCV_LIBS})
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(cs3307 ${CURL_LIBRARIES})

target_link_libraries(cs3307 Qt5::Widgets)
