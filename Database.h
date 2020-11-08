#ifndef DATABASE_CLASS_H
#define DATABASE_CLASS_H
#include <string>
#include <vector>

class Database {
    public:             
        vector<KnownPerson> known;        
        vector<UnknownPerson> unknown; 

    // Constructor
	Database()
    // Destructor
    ~Database());

    // Add Person Methods
    void addKnownPerson(KnownPerson kPerson);
    void addUnknownPerson(UnknownPerson ukPerson);

    
};

#endif