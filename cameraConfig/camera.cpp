/**
CS 3307 Security Project
Date: 2020-11-11
@author: Group53
@brief: camera.cpp file that implements the functions of the raspberry pi camera (Hardware)
**/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "camera.h"

using namespace std;

camera::camera(){}

camera::~camera(){}

/**
@brief: Starts the raspberry pi camera (hardware) and takes the time in miliseconds
@param: time
@return: none
**/
void camera::start(string time)
{
    string holder = "raspivid -t " + time;
    const char * c = holder.c_str();
    system(c);

}
/**
@brief: Takes a screenshot of the current feed on the camera, and saves a jpeg file
@param: none
@return: none
**/
void camera::screenShot()
{
    system("raspistill -o cam.jpg");
}

/**
@brief: Turns the raspberry pi camera off and ends execution
@param: none
@return: none
**/
void camera::off()
{
    terminate();
}

