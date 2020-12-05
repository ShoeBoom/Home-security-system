#include "Message.h"
#include "twilio.h"
Message::~Message() {

}
Message::Message() {
	time(&timer);
}
void Message::run(Result r) {
	time(&timer);
	if (difftime(timer, lasttimer) > 30 && r.personID == -2) {
		auto account_sid = "account_sid";
        auto auth_token = "auth_token";
        auto message_body = "Hmm...Looks like someone I don't recognize is at your door";
        auto from_number = "from_number";
        auto picture_url = "";
		bool verbose = false;

		auto opterr = 0;

		// Instantiate a twilio object and call send_message
		std::string response;
		auto twilio = std::make_shared<twilio::Twilio>(
			account_sid,
			auth_token
		);
		for (int i = 0; i < Database::getInstance().knownSize(); ++i) {
			twilio->send_message(
				Database::getInstance()[i].getPhoneNumber(),
				from_number,
				message_body,
				response,
				picture_url,
				verbose
			);
		}

		time(&lasttimer);
	}
}