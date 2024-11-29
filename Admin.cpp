#include "Admin.h"

// Name - Admin() Default Constructor
// Desc - Does nothing explicitly
// Preconditions - None
// Postconditions - None
Admin::Admin(){} //Default Constructor
// Name - LoadStudents
// Desc - Loads each student into m_students from file. Uses constant size.
// Preconditions - Requires file with valid student data
// Postconditions - m_students is populated with students
void Admin::LoadStudents(){
  string fName; //first name
  string lName; //last name
  int id; //student id

  ifstream myfile;
  myfile.open(STUDENT_FILE);//opens file
  int studentCount = 0; //set count of students
  //checks if the file is successfully open
  if(myfile.is_open()){
    while(myfile and studentCount != STUDENT_COUNT){
      // reads the first name, last name and student id of each line of file
      myfile >> fName >> lName >> id; 
      // sets students details
      m_students[studentCount].SetFName(fName);
      m_students[studentCount].SetLName(lName);
      m_students[studentCount].SetID(id);
      studentCount++;
    }
  }else{
    cout << "Failed to open student file" << endl;
  }
  myfile.close(); //closes file
  if(studentCount == STUDENT_COUNT){
    cout << studentCount << " students loaded." << endl;
  }   
}
// Name - LoadCourses
// Desc - Loads each course into m_coursess from file.
//        Courses have comma delimiters (check proj doc for delimiter help)
// Preconditions - Requires file with valid course data
// Postconditions - m_courses is populated with courses
void Admin::LoadCourses(){
  string prefix; // course prefix
  string number; //course number
  string name; //course name

  ifstream myfile;
  myfile.open(COURSE_FILE); //opens file
  int courseCount = 0; //sets course count

  if(myfile.is_open()){
    while(myfile and courseCount != COURSE_COUNT){
      getline(myfile, prefix, ','); //gets prefix and separates with a comma 
      getline(myfile, number, ','); //gets number and separates with a comma
      getline(myfile, name, '\n'); //gets course name
      //Sets course details
      m_courses[courseCount].SetPrefix(prefix);
      m_courses[courseCount].SetNumber(number);
      m_courses[courseCount].SetName(name);
      courseCount++;
    }
  }else{
    cout << "Failed to open course file" << endl;
  }
  myfile.close(); //closes file
  if(courseCount == COURSE_COUNT){
    cout << courseCount << " courses loaded." << endl;
  } 
}
// Name - AddCourse
// Desc - Asks user to choose a student then a course. Adds course to specific student.
// Preconditions - Requires m_students and m_courses to be populated
// Postconditions - Populates m_course_list for a chosen student
void Admin::AddCourse(){
  DisplayStudents(); //displays students

  int studentPos;
  cout << "Which student would you like to add a course to?" << endl;
  cin >> studentPos;

  // Check if the entered position is valid
  if(studentPos >= 1 && studentPos <= STUDENT_COUNT){
    //iterates through the course list and prints the particular course
    for(int i = 0; i < COURSE_COUNT; i++){
      PrintCourse(i);
    }
    //gets first name of the student from the position in the list
    string name = m_students[studentPos - 1].GetFName();
    int coursePos;
    
    while(coursePos < 1 or coursePos > COURSE_COUNT){
    cout << "Which course would you like to add to " << name << "?" << endl;
    cin >> coursePos;
    }
    if(coursePos >= 1 && coursePos <= COURSE_COUNT){
      //assigns course selected to selected student
      m_students[studentPos - 1].AddCourse(coursePos - 1);
      cout << "Course added" << endl;
    }
  }
}
// Name - DisplaySchedule
// Desc - Asks user to choose a student. Displays all scheduled courses for that student
// Preconditions - Requires m_students and m_courses to be populated
// Postconditions - Displays all courses from a chosen student
void Admin::DisplaySchedule(){
  DisplayStudents(); // Display a list of students

  int studentPos;
  while(studentPos < 1 or studentPos > STUDENT_COUNT){
  cout << "Which student would you like to display?" << endl;
  cin >> studentPos;
  }
  //gets first name of the student from the position in the list
  string name = m_students[studentPos - 1].GetFName();
  cout << "******" << name << "'s Schedule******" << endl;

  // Check if the entered position is valid
  if(studentPos >= 1 && studentPos <= STUDENT_COUNT){
    // Get the selected student's course list from m_students
    int studentCourseList[MAX_COURSES];
    for(int i = 0; i < MAX_COURSES; i++){
      studentCourseList[i] = -1;
    }
    for(int i = 0; i < MAX_COURSES; i++){
      studentCourseList[i] = m_students[studentPos - 1].GetCourse(i);
      int coursePos = studentCourseList[i];
      if(coursePos != -1){
        PrintCourse(coursePos);
      }
    }
  }
  cout << "******END SCHEDULE******" << endl;
}
// Name - PrintCourse
// Desc - Displays information about courses loaded into m_courses
// Preconditions - Passed the index from m_courses to display
// Postconditions - Displays index, prefix, number, and name of course at index
void Admin::PrintCourse(int index){
  //iterates through the courses and displays the details
  if(index >= 0 && index < COURSE_COUNT){
    cout << index + 1 << ". " << m_courses[index].GetPrefix()
    << " " << m_courses[index].GetNumber() << " " <<
    m_courses[index].GetName() << endl;
  }
}
// Name - PrintDetails
// Desc - Displays information about students loaded into m_students
// Preconditions - Passed the index from m_students to display
// Postconditions - Displays index, first name, last name, and id at index
void Admin::PrintDetails(int index){
  // iterate through the students and dispalys their details
  if(index >= 0 && index < STUDENT_COUNT){ 
    cout << index + 1 << ". " << m_students[index].GetFName()
    << " " << m_students[index].GetLName() << " " <<
    m_students[index].GetID() << endl;
  }
}
// Name - StartAdmin()
// Desc - Calls AdminTitle then loads the student file by calling LoadStudents
//        Then loads courses by calling LoadCourses.
//        Manages the game itself continually by calling MainMenu until the
//        user chooses 5 (and returns 5)
// Preconditions - None
// Postconditions - Continually checks to see if user has entered 5
void Admin::StartAdmin(){
  AdminTitle(); //prints admin title
  LoadStudents(); //loads students
  LoadCourses(); //loads courses
  cout << "What is the name of your School?" << endl;
  getline(cin, m_schoolName);

  int choice;

  do{
    choice = MainMenu(); //calls main menu contnuously until 5 is entered
  }while(choice != 5);
}
// Name: DisplayStudents()
// Desc - Displays the Admin's students
// Preconditions - m_students has been populated
// Postconditions - Displays a numbered list of students (starting with 1)
void Admin::DisplayStudents(){
  //iterates through the students and displays the details
  for(int i = 0; i < STUDENT_COUNT; i++){
    cout << i + 1 << ". " << m_students[i].GetFName() << " "
    << m_students[i].GetLName() << " " << "(" << 
    m_students[i].GetID() << ")" << endl;
  }
}
// Name: PrintMenu(int &) (passed by reference)
// Desc - Displays menu and allows user to choose 1-5.
// Preconditions - Called from MainMenu
// Postconditions - Updates choice based on user choice.
void Admin::PrintMenu(int &choice){
  do{
    cout << "What would you like to do in " << m_schoolName << "'s Admin Portal? " << endl;
    cout << "1. Display your School's Students" << endl;
    cout << "2. Search for a Student" << endl;
    cout << "3. Add Course to Student" << endl;
    cout << "4. Display Schedule" << endl;
    cout << "5. Quit" << endl;

    cin >> choice;
  }while(choice < 1 or choice > 5); //correct choice input must be betwwn 1 - 5
}
// Name: MainMenu()
// Desc - Calls PrintMenu. Processes choice from menu
// Preconditions - User will choose an item (1-5)
// Postconditions - Keeps running until user chooses 5. Returns choice.
int Admin::MainMenu(){
  int choice;
  PrintMenu(choice);

  switch (choice){
    case 1:
      DisplayStudents(); 
      break;
    case 2:
      SearchStudents(); 
      break;
    case 3:
      AddCourse();
      break;
    case 4:
      DisplaySchedule();
      break;
    case 5:
      cout << "Thanks for using Admin" << endl; //message displayed when choice is 5
      break;
  }
  return choice;
}
// Name: SearchName()
// Desc - Searches m_students for a name (first OR last name) - Case sensitive
// Preconditions - m_students are populated
// Postconditions - Returns all matches of a name (can be more than one)
void Admin::SearchName(){
  string name; //search name
  string fName;
  string lName;
  cout << "What name would you like to search for?" << endl;
  cin >> name;

  bool found = false; //as long as the student is not found
  int count = 0; // sets number of students found

  //iterates through the students and sets their first and last name accordingly
  for(int i = 0; i < STUDENT_COUNT; i++){
    fName = m_students[i].GetFName();
    lName = m_students[i].GetLName();

    //compares if the name is similar to first name or last name and is case sensitive
    if(name == fName or name == lName){ 
      found = true; //student has been found
      cout << i + 1 << ". "<< fName << " " << lName << " ("
      << m_students[i].GetID() <<")"<< endl;
      count++;
    }
  }
  if(count > 0){
    cout << count << " matches found." << endl;
  }
  if(!found){
    cout<< "No matches found." << endl; // if no students are found
  }
  
}



// Name: SearchID()
// Desc - Searches m_students for an ID
// Preconditions - m_students are populated
// Postconditions - Returns all matches of the number (all numbers match)
void Admin::SearchID(){
  int searchID;
  int studentID;
  cout << "What ID would you like to search for?" << endl;
  cin >> searchID;

  bool found = false;//as long as the student is not found
  int count = 0; // sets number of students found

  //iterates through the students and sets their first and last name accordingly
  for(int i = 0; i < STUDENT_COUNT; i++){
    studentID = m_students[i].GetID();

    //compares if the student id is same as the search id
    if(searchID == studentID){
      found = true; //student is found
      cout << i + 1 << ". "<< m_students[i].GetFName() << " " 
      << m_students[i].GetLName() << " ("
      << studentID <<")"<< endl;
      count++;
    }
  }
  if(count > 0){
    cout << count << " matches found" << endl;
  }
  if(!found){
    cout<< "No matches found" << endl;// if no students are found
  }
 
}
// Name: SearchStudents()
// Desc - Prompts user to either choose name or ID
// Preconditions - m_students are populated
// Postconditions - Either calls SearchName() or SearchID()
void Admin::SearchStudents(){
  int choice;
  while(choice < 1 or choice > 2){
  cout << "What would you like to search" << endl;
  cout << "1. Name" << endl;
  cout << "2. ID" << endl;

  cin >> choice;
  }
  
  if(choice == 1){
    SearchName();
  }else if(choice == 2){
    SearchID();
  }
}
