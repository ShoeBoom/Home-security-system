/**
CS 3307 Security Project
Date: 2020-11-11
Description: camera.cpp file that implements the functions of the raspberry pi camera (Hardware)
**/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "camera.h"

using namespace std;

camera::camera(){}

camera::~camera(){}

/**
start
Parameters: time
Description: Starts the raspberry pi camera (hardware) and takes the time in miliseconds
Return: none
**/
void camera::start(string time)
{
    string holder = "raspivid -t " + time;
    const char * c = holder.c_str();
    system(c);

}
/**
screenShot
Parameters: none
Description: Takes a screenshot of the current feed on the camera, and saves a jpeg file
Return: none
**/
void camera::screenShot()
{
    system("raspistill -o cam.jpg");
}

/**
off
Parameters: none
Description: Turns the raspberry pi camera off and ends execution
Return: none
**/
void camera::off()
{
    terminate();
}

