#ifndef DATABASE_CLASS_H
#define DATABASE_CLASS_H
#include <string>
#include <vector>
#include "KnownPerson.h"
#include "UnknownPerson.h"

class Database {
 public:
  void operator=(const Database &) = delete;
  static Database &getInstance() {
	  static Database _instance;
	  return _instance;
  }
  // Destructor
  ~Database();

  // Add Person Methods
  int addKnownPerson(KnownPerson kPerson);
  void addUnknownPerson(UnknownPerson ukPerson);
  KnownPerson operator[](int b);
  int knownSize();
 private:
  Database();
  std::vector<KnownPerson> known;
  std::vector<UnknownPerson> unknown;

};

#endif
