//Title: Admin.h
//Author: Jeremy Dixon
//Date: 2/10/2023
//Description: This is part of the PotionCraft Project in CMSC 202 @ UMBC

#ifndef ADMIN_H //Header Guard
#define ADMIN_H //Header Guard

#include <fstream>
#include <iostream>
#include <string>
#include "Course.h" //Must include course
#include "Student.h" //Must include student

using namespace std;

//Constants (Do not edit)
const string STUDENT_FILE = "proj2_students.txt"; //File of students
const string COURSE_FILE = "proj2_courses.txt"; // File of courses
const int STUDENT_COUNT = 50; // Student count constant
const int COURSE_COUNT = 11; // Course count constant

//No additional variables or functions allowed
class Admin{
public:
  // Name - Admin() Default Constructor
  // Desc - Does nothing explicitly
  // Preconditions - None
  // Postconditions - None
  Admin(); //Default Constructor
  // Name - LoadStudents
  // Desc - Loads each student into m_students from file. Uses constant size.
  // Preconditions - Requires file with valid student data
  // Postconditions - m_students is populated with students
  void LoadStudents();
  // Name - LoadCourses
  // Desc - Loads each course into m_coursess from file.
  //        Courses have comma delimiters (check proj doc for delimiter help)
  // Preconditions - Requires file with valid course data
  // Postconditions - m_courses is populated with courses
  void LoadCourses();
  // Name - AddCourse
  // Desc - Asks user to choose a student then a course. Adds course to specific student.
  // Preconditions - Requires m_students and m_courses to be populated
  // Postconditions - Populates m_course_list for a chosen student
  void AddCourse();
  // Name - DisplaySchedule
  // Desc - Asks user to choose a student. Displays all scheduled courses for that student
  // Preconditions - Requires m_students and m_courses to be populated
  // Postconditions - Displays all courses from a chosen student
  void DisplaySchedule();
  // Name - PrintCourse
  // Desc - Displays information about courses loaded into m_courses
  // Preconditions - Passed the index from m_courses to display
  // Postconditions - Displays index, prefix, number, and name of course at index
  void PrintCourse(int);
  // Name - PrintDetails
  // Desc - Displays information about students loaded into m_students
  // Preconditions - Passed the index from m_students to display
  // Postconditions - Displays index, first name, last name, and id at index
  void PrintDetails(int);
  // Name - StartAdmin()
  // Desc - Calls AdminTitle then loads the student file by calling LoadStudents
  //        Then loads courses by calling LoadCourses.
  //        Manages the game itself continually by calling MainMenu until the
  //        user chooses 5 (and returns 5)
  // Preconditions - None
  // Postconditions - Continually checks to see if user has entered 5
  void StartAdmin();
  // Name: DisplayStudents()
  // Desc - Displays the Admin's students
  // Preconditions - m_students has been populated
  // Postconditions - Displays a numbered list of students (starting with 1)
  void DisplayStudents();
  // Name: PrintMenu(int &) (passed by reference)
  // Desc - Displays menu and allows user to choose 1-5.
  // Preconditions - Called from MainMenu
  // Postconditions - Updates choice based on user choice.
  void PrintMenu(int &choice);
  // Name: MainMenu()
  // Desc - Calls PrintMenu. Processes choice from menu
  // Preconditions - User will choose an item (1-5)
  // Postconditions - Keeps running until user chooses 5. Returns choice.
  int MainMenu();
  // Name: SearchName()
  // Desc - Searches m_students for a name (first OR last name) - Case sensitive
  // Preconditions - m_students are populated
  // Postconditions - Returns all matches of a name (can be more than one)
  void SearchName();
  // Name: SearchID()
  // Desc - Searches m_students for an ID
  // Preconditions - m_students are populated
  // Postconditions - Returns all matches of the number (all numbers match)
  void SearchID();
  // Name: SearchStudents()
  // Desc - Prompts user to either choose name or ID
  // Preconditions - m_students are populated
  // Postconditions - Either calls SearchName() or SearchID()
  void SearchStudents();
  // Name: AdminTitle()
  // Desc - Title for Admin (Do not edit)
  // Do NOT copy to Admin.cpp (use this version)
  // Preconditions - None
  // Postconditions - None
  void AdminTitle(){
    cout << "  AA  DDD   MM MM  IIIIII NN   NN" << endl;
    cout << " A  A D  D MM M MM   II   NNN  NN" << endl;
    cout << " AAAA D  D MM   MM   II   NN N NN" << endl;
    cout << " A  A D  D MM   MM   II   NN  NNN" << endl;
    cout << " A  A DDD  MM   MM IIIIII NN   NN" << endl;
  }
private:
  Student m_students [STUDENT_COUNT]; // Students for application (loaded from file)
  Course m_courses[COURSE_COUNT]; //All courses for application (loaded from file)
  string m_schoolName; //Name of the school
};

#endif //Exit Header Guard
