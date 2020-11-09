#ifndef DATABASE_CLASS_H
#define DATABASE_CLASS_H
#include <string>
#include <vector>
#include "KnownPerson.h"
#include "UnknownPerson.h"

class Database {
 public:
  std::vector<KnownPerson> known;
  std::vector<UnknownPerson> unknown;

  // Constructor
  Database();
  // Destructor
  ~Database();

  // Add Person Methods
  void addKnownPerson(KnownPerson kPerson);
  void addUnknownPerson(UnknownPerson ukPerson);

    
};

#endif