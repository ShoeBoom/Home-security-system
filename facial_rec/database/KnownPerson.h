/** 
 * Known person class
 * Stores information about the known person (name, phone number, images).
 * @author group53
 */

#ifndef KNOWNPERSON_CLASS_H
#define KNOWNPERSON_CLASS_H
#include <string>
#include <vector>
#include <opencv2/core.hpp>

class KnownPerson {
 public:
  
  std::string firstName; /**< person's first name */ 
  std::string lastName; /**< person's last name */ 
  std::string phoneNumber; /**< person's phone number */ 
  std::vector<cv::Mat> images; /**< person's images */ 

  /** 
   * Constructor that creates a known person object
   * @param first_name first name
   * @param last_name last name
   * @param phone_number phone number
   * @param images images of known person
   */
  KnownPerson(const std::string &first_name,
              const std::string &last_name,
              const std::string &phone_number,
              const std::vector<cv::Mat> &images);

  /** 
   * Destructor
   */
  ~KnownPerson();

  /** 
   * Setter methods
   */
  void setFirstName(std::string fName);
  void setLastName(std::string lName);
  void setPhoneNumber(std::string pNum);
  void setImage(std::vector<cv::Mat> imgs);

  /** 
   * Getter methods
   */
  std::string getFirstName();
  std::string getLastName();
  std::string getPhoneNumber();
  std::vector<cv::Mat> getImage();
};

#endif