#include "Student.h"

// Name: Student (default constructor)
// Desc: Creates a new student
// Preconditions: None
// Postconditions: Creates a default object
Student::Student(){
  m_fName = "";
  m_lName = "";
  m_id = 0;
  for (int i = 0; i < MAX_COURSES; i++){
    m_course_list[i] = -1;
  }
}

string Student::GetFName(){
  return m_fName;
} //Returns m_fName

string Student::GetLName(){
  return m_lName;
} //Returns m_lName

int Student::GetID(){
  return m_id;
} //Returns m_ID

void Student::SetLName(string lName){
  m_lName = lName;
} //Sets m_lName

void Student::SetFName(string fName){
  m_fName = fName;
} //Sets m_fName

void Student::SetID(int id){
  m_id = id;
} //Sets m_ID

// Name: AddCourse
// Desc: Adds a specific course to current schedule. Adds index of course from m_courses to
//       m_course_list. Can hold maximum of 5 courses. After that, indicates schedule full.
// Preconditions: Passed index from m_courses
// Postconditions: Populates m_course_list (up to MAX_COURSES)
void Student::AddCourse(int index){
  bool added = false;  // Initialize a boolean flag to track if the course was added

  // Iterate through the course list
  int i = 0;
  while(i < MAX_COURSES && !added){
    if(m_course_list[i] == -1){
      m_course_list[i] = index;
      added = true;  // Set the flag to true to indicate the course was added
    }
    i++;
  }
}

// Name: GetCourse
// Desc: Returns the index of the course
// Preconditions: Passed the location in m_course_list to get data (up to MAX_COURSES)
// Postconditions: Returns the index of a course at passed loc
int Student::GetCourse(int loc){
  if(loc >= 0 && loc < MAX_COURSES){
    return m_course_list[loc];
  }
  else{
    cout << "Invalid Location." << endl;
    return -1;
  }
}