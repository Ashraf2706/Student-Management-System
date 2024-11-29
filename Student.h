//Title: Student.h
//Author: Jeremy Dixon
//Date: 9/20/2023
//Description: This is part of the student management system for CMSC202@UMBC

#ifndef STUDENT_H //Header Guard
#define STUDENT_H //Header Guard

#include <iostream>
#include <string>
#include <fstream>
#include "Course.h" //Must include course because a student has an array to hold courses
using namespace std;

//Constants
const int MAX_COURSES = 5; //Max number of courses per student

class Student{
 public:
  // Name: Student (default constructor)
  // Desc: Creates a new student
  // Preconditions: None
  // Postconditions: Creates a default object
  Student();
  string GetFName(); //Returns m_fName
  string GetLName(); //Returns m_lName
  int GetID(); //Returns m_ID
  void SetLName(string lName); //Sets m_lName
  void SetFName(string fName); //Sets m_fName
  void SetID(int id); //Sets m_ID

  // Name: AddCourse
  // Desc: Adds a specific course to current schedule. Adds index of course from m_courses to
  //       m_course_list. Can hold maximum of 5 courses. After that, indicates schedule full.
  // Preconditions: Passed index from m_courses
  // Postconditions: Populates m_course_list (up to MAX_COURSES)
  void AddCourse(int index);
  // Name: GetCourse
  // Desc: Returns the index of the course
  // Preconditions: Passed the location in m_course_list to get data (up to MAX_COURSES)
  // Postconditions: Returns the index of a course at passed loc
  int GetCourse(int loc);
  
 private:
  string m_fName; // First name of student
  string m_lName; // Last name of student
  int m_id; // Student ID
  int m_course_list[MAX_COURSES]; // List of courses that the student is enrolled in
};

#endif
