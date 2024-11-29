#include "Course.h"

// Name: Course (default constructor)
  // Desc: Creates a new course
  // Preconditions: None
  // Postconditions: Creates a new course with empty values
  Course::Course(){
    m_name = "";
    m_number = "";
    m_prefix = "";
  }

  void Course::SetPrefix(string prefix){
    m_prefix = prefix;
  } //Sets m_prefix

  void Course::SetNumber(string number){
    m_number = number;
  } //Sets m_number

  void Course::SetName(string name){
    m_name = name;
  } //Sets m_name

  string Course::GetPrefix(){
    return m_prefix;
  } //Returns m_prefix

  string Course::GetNumber(){
    return m_number;
  } //Returns m_number

  string Course::GetName(){
    return m_name;
  } //Returns m_name