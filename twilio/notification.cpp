#include "notification.h"
//#include <iostream>
#include "twilio.h"
#include <string>
using namespace std;

// Constructor that creates a database object
notification::notification() {
    string account_sid = "account_sid";
    string auth_token = "auth_token";
    string message_body = "Hmm...Looks like someone I don't recognize is at your door";
    string from_number = "from_number";
    string to_number = "to_number";
    string picture_url = "";
    bool verbose = false;

}

string response;
auto Twilio::twilio = std::make_shared<twilio::Twilio>(
    account_sid,
    auth_token
);

bool message_success = twilio->send_message(
        to_number,
        from_number,
        message,
        response,
        picture_url,
        verbose
);

// Destructor
notification::~notification() {
}


