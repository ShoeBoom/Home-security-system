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
Database::~Database() {
}

// Add known person
int Database::addKnownPerson(KnownPerson kPerson) {
	known.push_back(kPerson);
	return knownSize() - 1;
}

// Add unknown person
void Database::addUnknownPerson(UnknownPerson ukPerson) {
	unknown.push_back(ukPerson);
}

KnownPerson Database::operator[](int b) {
	return known[b];
}

int Database::knownSize() const {
	return known.size();
}

