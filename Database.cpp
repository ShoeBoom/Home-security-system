#include "Database.h"
#include "KnownPerson.h"
#include "UnknownPerson.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constructor that creates a database object
Database::Database() { 
}

// Destructor
Database::-Database(){
}

// Add known person
void addKnownPerson(KnownPerson kPerson) {
	known.push_back(kPerson);
}

// Add unknown person
void addUnknownPerson(UnknownPerson ukPerson) {
	unknown.push_back(ukPerson);
}

