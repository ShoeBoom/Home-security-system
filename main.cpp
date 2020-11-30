#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <unistd.h>

#include <opencv2/imgproc/imgproc.hpp>

#include "facial_rec/FaceRecognizer.h"
#include "facial_rec/camera/Camera.h"

using namespace cv;
using namespace std;
int main(int argc, const char *argv[]) {
	// still inaccurate due to sample size
	Camera camera = *Camera::getInstance();

	vector<KnownPerson> known;

	int i = 0;
	char addKP = 'Y';

	while (addKP!='N' || addKP !='n') {	
		cout << "Would you like to add a new known person to the database? (Y/N): ";
		cin.get(addKP);
		cin.ignore();

		if (addKP=='Y' || addKP =='y') {
			// Get Information about new known person.
			cout << "Please provide the following information about the new known person:\n";
			string fName;
			cout << "First Name: ";
			getline(cin, fName);
			string lName;
			cout << "Last Name: ";
			getline(cin, lName);
			string pNum;
			cout << "Phone Number: ";
			getline(cin, pNum);

			// Scan new face
			cout << "\n----- READY TO SCAN NEW FACE -----\n";
			cout << "PLEASE TAKE MULTIPLE PHOTOS AND REMAIN WITHIN YOUR CAMERA FRAME.\n";	
			vector<cv::Mat> images;
			cout << "Ready to add first image for " << fName << " " << lName << ".\n" << endl;
			cout << "Image will be caputured after 3 seconds..." << endl;
			sleep(3);
			cout << "Adding first image for " << fName << " " << lName << "..." << endl;
			Mat frame = camera.captureGrayscale();
			images.push_back(frame);
			cout << "Added image for " << fName << " " << lName << ".\n" << endl;
			char contScan = 'Y';
			while (contScan != 'N') {
				cout << "Would you like to add another image for " << fName << " " << lName << " (Y/N)?: " << endl;
				cin.get(contScan);
				cin.ignore();
				if (contScan=='Y' || contScan =='y') {
					cout << "Image will be caputured after 3 seconds..." << endl;
					sleep(3);
					cout << "Adding another image for " << fName << " " << lName << "..." << endl;
					Mat frame = camera.captureGrayscale();
					images.push_back(frame);
					cout << "Added image for " << fName << " " << lName << ".\n" << endl;
				} else { 
					if (contScan=='N' || contScan =='n') {
						cout << "Ok no additional photos will be added for " << fName << " " << lName << ".\n" << endl;
						break;
					} else {
						cout << "INVALID INPUT: Please enter enter a valid input (Y or N).\n";
					}
				}
			}

			// Add the new known person to database
			cout << "----- PREPARING TO ADD " << fName << " " << lName << " TO THE KNOWN DATABASE -----" << endl;
			KnownPerson person = KnownPerson(fName, lName, pNum, images);
			known.push_back(person);
			cout << "Added " << fName << " " << lName << " to database.\n" << endl;

		} else { 
			if (addKP=='N' || addKP =='n') {
				cout << "Ok no additional known people will be added.\n" << endl;
				break;
			} else {
				cout << "INVALID INPUT: Please enter enter a valid input (Y or N).\n";
			}
			
		}

		
	}
	
	cout << "----- LAUNCHING FACIAL RECOGNITION -----" << endl;
	cout << "Camera capture will be launched after 5 seconds...\n" << endl;
	sleep(5);
	
	FaceRecognizer recognizer = FaceRecognizer(known);

	//--- GRAB AND WRITE LOOP
	cout << "Start grabbing..." << endl
	     << "Press any key to terminate." << endl;

	for (;;) {

		Mat frame = camera.captureGrayscale();

		Result result = recognizer.predict(frame);
		cout << "Detected: " <<result.person.firstName << " " << result.person.lastName << " - Confidence: " << result.confidence << endl;

		// show live and wait for a key with timeout long enough to show images
		imshow("Live", frame);

		if (waitKey(5) >= 0)
			break;
	}

	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}