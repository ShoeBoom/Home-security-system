/** 
 * Database class.
 * Database that stores known and unknown people.
 * @author group53
 */

#ifndef DATABASE_CLASS_H
#define DATABASE_CLASS_H
#include <string>
#include <vector>
#include "KnownPerson.h"
#include "UnknownPerson.h"

class Database {
 public:
  /** 
   * Constructor that creates a database object
   */
  void operator=(const Database &) = delete;
  
   /** 
   * Create an instance of the database class using Singleton design pattern
   */ 
  static Database &getInstance() {
	  static Database _instance;
	  return _instance;
  }
  /** 
   * Descructor
   */
  ~Database();

  /** 
   * Add a known person to the database
   * @param kPerson new known person
   */
  int addKnownPerson(KnownPerson kPerson);

  /** 
   * Add an unknown person to the database
   * @param ukPerson new known person
   */
  void addUnknownPerson(UnknownPerson ukPerson);
  
  /** 
   * Get a known person from the database
   * @param b known person index
   */
  KnownPerson operator[](int b);
  
  /**
  * Get number of known people
  */
  int knownSize();
 
 
 private:
  Database();
  std::vector<KnownPerson> known;
  std::vector<UnknownPerson> unknown;

};

#endif
