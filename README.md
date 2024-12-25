![image](https://github.com/user-attachments/assets/76c0eeaf-d10b-4529-8151-cafae5ed451a)# **Employee-Management-System**
This project is an Employee Management System implemented in C++. It allows administrators to manage employee details using a binary search tree structure. The system includes functionality to add, edit, delete, search, and display employees, as well as generate salary slips and search employees by department.
## **Features**
1. **Admin Login:** Secure access to the system using predefined credentials.
2. **Employee Management:** Add, edit, delete, and search employees.
3. **Display Employees:** View all employees in a tabular format.
4. **Generate Salary Slip:** Quickly generate a salary slip for any employee.
5. **Search by Department:** Find employees based on their department.
6. **Robust Input Validation:** Ensures valid inputs for all fields.

### **Instructions to Compile and Run the Code**
**Prerequisites:**
A C++ compiler (e.g., GCC or Clang).
A terminal or IDE that supports C++ (e.g., Visual Studio Code, CLion,DEV C/c++).
**Steps to Compile:**
Save the code in a file named **EmployeeManagementSystem.cpp**.
Open a terminal or command prompt in the directory containing the file.
Run the following command to compile the code:
**g++ -o EmployeeManagementSystem EmployeeManagementSystem.cpp**
This command will generate an executable file named EmployeeManagementSystem.
**Steps to Run:**
After successful compilation, execute the program by running:
**./EmployeeManagementSystem**
Follow the on-screen instructions to use the system. 
#### ** Special Requirements**
**Libraries Used:**
This project uses the following standard libraries:
**<iostream>:** For input and output operations.
**<iomanip>:** For formatted output.
**<string>:** To handle employee names and departments.
**<queue>:** For breadth-first search when searching by department.
##### **Admin Credentials**
To access the system, use the following credentials:
Username: **admin**
Password: **password**
###### **System Workflow**
**1. Login:** Authenticate using the admin credentials.
**2. Main Menu:**
Insert a new employee.
Display all employees.
Search for an employee by ID.
Edit an employee's details.
Delete an employee.
Generate a salary slip.
Search employees by department.
**3. Exit:** Quit the system.
####### **Sample**
**Adding an Employee**
```Enter Employee Details:
ID: 101
Name: John Doe
Department: IT
Salary: 60000

Employee Added Successfully!```
**Displaying Employees**
```List of Employees:
ID        Name                Department          Salary
---------------------------------------------------------
101       John Doe            IT                  60000.00```
**Generating a Salary Slip**
```Enter Employee ID for Salary Slip: 101

================ Salary Slip =================
Employee ID: 101
Name: John Doe
Department: IT
Salary: $60000.00
============================================```
