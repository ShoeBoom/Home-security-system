/**
@brief: Provides the system a method of sending a text notification.
@author:Group53
**/

#include "notification.h"
//#include <iostream>
#include "twilio.h"
#include <string>
using namespace std;

/**
@brief: Constructor that creates a database object
@param: none
@return: none
**/
notification::notification() {
    string account_sid = "***REMOVED***";
    string auth_token = "***REMOVED***";
    string message_body = "Hmm...Looks like someone I don't recognize is at your door";
    string from_number = "***REMOVED***";
    string to_number = "***REMOVED***";
    string picture_url = "";
    bool verbose = false;

}

string response;
auto Twilio::twilio = std::make_shared<twilio::Twilio>(
    account_sid,
    auth_token
);

//Determines if the message was sent successfully
bool message_success = twilio->send_message(
        to_number,
        from_number,
        message,
        response,
        picture_url,
        verbose
);

/**
@brief: Destructor
@param: none
@return: none
**/
notification::~notification() {
}


