
# Student Management System

## Overview
This project implements a Student Management System in C++. It provides functionality for managing student records, courses, and schedules. Administrators can load student and course data from files, assign courses to students, search for students by name or ID, and display schedules for individual students.

## Features

### Student Management
- **Load Students**: Populate the system with student data from a file.
- **Search Students**:
  - By Name: Search for students by their first or last name.
  - By ID: Search for students by their unique ID.
- **Add Courses**: Assign courses to students, limited to a maximum of 5 courses per student.
- **Display Students**: List all students with their names and IDs.

### Course Management
- **Load Courses**: Populate the system with course data from a file.
- **Display Courses**: Show all available courses, including their prefix, number, and name.

### Schedule Management
- **Display Schedule**: Show the list of courses assigned to a specific student.

### Menu-Driven Interface
- Interactive menu for administrators to manage students, courses, and schedules.

## Files

### Source Files
1. **`Admin.cpp` & `Admin.h`**:
   - Manages the core functionality of the student management system.
   - Handles loading of student and course data, and provides methods for assigning courses and displaying schedules.

2. **`Student.cpp` & `Student.h`**:
   - Implements the `Student` class.
   - Handles student attributes (first name, last name, ID) and manages their course assignments.

3. **`Course.cpp` & `Course.h`**:
   - Implements the `Course` class.
   - Stores course attributes such as prefix, number, and name.

### Data Files
- **`proj2_students.txt`**: Contains student data in the format:
  ```
  <First Name> <Last Name> <ID>
  ```
  Example:
  ```
  Channing Barrera 54321
  Abdul Jones 57353
  ```

- **`proj2_courses.txt`**: Contains course data in the format:
  ```
  <Prefix>,<Number>,<Name>
  ```
  Example:
  ```
  CMSC,202,Computer Science II
  MATH,241,Calculus III
  ```

## Installation and Execution

1. Compile the program:
   ```bash
   g++ -o student_management Admin.cpp Student.cpp Course.cpp
   ```
2. Run the program:
   ```bash
   ./student_management
   ```

## Usage

### Main Menu Options
1. **Display Students**: Lists all students with their names and IDs.
2. **Search for a Student**: Search for students by name or ID.
3. **Add Course to Student**: Assign a course to a selected student.
4. **Display Schedule**: View the course schedule for a specific student.
5. **Quit**: Exit the program.

### Example Commands
#### Load Students
Students are loaded from `proj2_students.txt` into the system using the `LoadStudents` method.

#### Add Course
Assign a course to a student by selecting the student and course from the respective lists.

#### Display Schedule
View a specific student's schedule, showing all courses they are enrolled in.

## Dependencies
- **Standard C++ Libraries**:
  - `<iostream>`
  - `<fstream>`
  - `<string>`

## Authors
- **Ashraf Kawooya**
- **Date**: 9/20/2023

## License
This project is for educational purposes and does not include warranties or guarantees.
