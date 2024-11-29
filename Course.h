//Title: Course.h
//Author: Jeremy Dixon
//Date: 9/20/2023
//Description: This is part of the student management system for CMSC202@UMBC
#ifndef COURSE_H //Header Guard
#define COURSE_H //Header Guard

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Course{
 public:
  // Name: Course (default constructor)
  // Desc: Creates a new course
  // Preconditions: None
  // Postconditions: Creates a new course with empty values
  Course(); 

  void SetPrefix(string prefix); //Sets m_prefix
  void SetNumber(string number); //Sets m_number
  void SetName(string name); //Sets m_name
  string GetPrefix(); //Returns m_prefix
  string GetNumber(); //Returns m_number
  string GetName(); //Returns m_name
  
 private:
  string m_prefix; // Prefix of course e.g. CMSC
  string m_number; // Number of course e.g. 202
  string m_name; // Name of course e.g. Computer Science II
};

#endif //Header Guard
