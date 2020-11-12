/**
CS 3307 Security Project
Date: 2020-11-11
Description: camera.h file that provides a prototype to the camera class
**/

#ifndef CAMERA_H
#define CAMERA_H
#include<string>
class camera
{
    public:
        //constructor
        camera();

        //Destructor
        ~camera();
        //Starts the rasperry pi camera
        void start(std::string time);
        //Takes a screenshot
        void screenShot();
        //Turns of the camera
        void off();
};

#endif // CAMERA_H
