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
  int addKnownPerson(KnownPerson kPerson);
  void addUnknownPerson(UnknownPerson ukPerson);
  KnownPerson operator[](int b);
  int knownSize();
    
    

};

#endif
