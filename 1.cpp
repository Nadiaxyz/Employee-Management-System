#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Employee Node 
struct Employee {
    int id;
    string name;
    string department;
    double salary;
    Employee* left;  // Tree structure
    Employee* right;
};

// Global Root for Binary Tree
Employee* root = nullptr;

// Admin Login Credentials
const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "password";

// Function Prototypes
void adminLogin();
void mainMenu();
void insertEmployee();
void displayEmployees(Employee* node);
void searchEmployee();
void editEmployee();
void deleteEmployee();
void generateSalarySlip();
void searchByDepartment();
Employee* deleteNode(Employee* root, int id);
void printEmployee(Employee* emp);
void displayTableHeader();
void clearScreen();
int getValidatedInput();
Employee* findEmployeeById(Employee* node, int id);

// Helper Functions
Employee* createEmployee(int id, string name, string department, double salary) {
    Employee* newEmployee = new Employee;
    newEmployee->id = id;
    newEmployee->name = name;
    newEmployee->department = department;
    newEmployee->salary = salary;
    newEmployee->left = newEmployee->right = nullptr;
    return newEmployee;
}

// Function to get validated input
int getValidatedInput() {
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n\tInvalid input! Please enter a valid number: ";
    }
    return input;
}

// Find employee by ID in Binary Tree
Employee* findEmployeeById(Employee* node, int id) {
    if (!node || node->id == id)
        return node;
    if (id < node->id)
        return findEmployeeById(node->left, id);
    return findEmployeeById(node->right, id);
}

// Admin Login Function
void adminLogin() {
    string username, password;
    cout << "\n\t================ Admin Login =================\n";
    cout << "\tUsername: ";
    cin >> username;
    cout << "\tPassword: ";
    cin >> password;

    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
        cout << "\n\tLogin Successful!\n";
        mainMenu();
    }
    else {
        cout << "\n\tInvalid Credentials. Try again.\n";
        adminLogin();
    }
}

void insertEmployee() {
    int id;
    string name, department;
    double salary;

    cout << "\n\tEnter Employee Details:\n";
    cout << "\tID: ";
    id = getValidatedInput();

    cin.ignore(10000, '\n');
    do {
        cout << "\tName: ";
        getline(cin, name);
        if (name.empty())
            cout << "\tName cannot be empty. Please enter a valid name.\n";
    } while (name.empty());

    do {
        cout << "\tDepartment: ";
        getline(cin, department);
        if (department.empty())
            cout << "\tDepartment cannot be empty. Please enter a valid department.\n";
    } while (department.empty());

    cout << "\tSalary: ";
    while (!(cin >> salary)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n\tInvalid input! Please enter a valid number for salary: ";
    }

    Employee* newEmployee = createEmployee(id, name, department, salary);

    if (root == nullptr) {
        root = newEmployee;
        cout << "\n\tEmployee Added Successfully!\n";
        return;
    }

    Employee* current = root;
    Employee* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (id < current->id)
            current = current->left;
        else
            current = current->right;
    }

    if (id < parent->id)
        parent->left = newEmployee;
    else
        parent->right = newEmployee;

    cout << "\n\tEmployee Added Successfully!\n";
}

// Display Employees in Tabular Form
void displayEmployees(Employee* node) {
    if (node == nullptr) return;
    displayEmployees(node->left);
    printEmployee(node);
    displayEmployees(node->right);
}

void printEmployee(Employee* emp) {
    cout << left << setw(10) << emp->id
        << setw(20) << emp->name
        << setw(20) << emp->department
        << setw(10) << fixed << setprecision(2) << emp->salary << endl;
}

void displayTableHeader() {
    cout << left << setw(10) << "ID"
        << setw(20) << "Name"
        << setw(20) << "Department"
        << setw(10) << "Salary" << endl;
    cout << string(60, '-') << endl;
}

// Search Employee by ID
void searchEmployee() {
    int id;
    cout << "\n\tEnter Employee ID to Search: ";
    id = getValidatedInput();

    Employee* emp = findEmployeeById(root, id);
    if (emp) {
        cout << "\n\tEmployee Found:\n";
        displayTableHeader();
        printEmployee(emp);
    }
    else {
        cout << "\n\tEmployee Not Found.\n";
    }
}

// Edit Employee Details
void editEmployee() {
    int id;
    cout << "\n\tEnter Employee ID to Edit: ";
    id = getValidatedInput();

    Employee* emp = findEmployeeById(root, id);
    if (emp) {
        cout << "\n\tEditing Employee: " << emp->name << endl;
        cin.ignore(10000, '\n');
        cout << "\tNew Name: "; getline(cin, emp->name);
        cout << "\tNew Department: "; getline(cin, emp->department);
        cout << "\tNew Salary: ";
        while (!(cin >> emp->salary)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n\tInvalid input! Please enter a valid number for salary: ";
        }
        cout << "\n\tEmployee Details Updated Successfully!\n";
    }
    else {
        cout << "\n\tEmployee Not Found.\n";
    }
}

// Delete Employee
void deleteEmployee() {
    int id;
    cout << "\n\tEnter Employee ID to Delete: ";
    id = getValidatedInput();
    root = deleteNode(root, id);
}

Employee* deleteNode(Employee* node, int id) {
    if (node == nullptr) {
        cout << "\n\tEmployee Not Found.\n";
        return node;
    }

    if (id < node->id)
        node->left = deleteNode(node->left, id);
    else if (id > node->id)
        node->right = deleteNode(node->right, id);
    else {
        if (node->left == nullptr) {
            Employee* temp = node->right;
            delete node;
            cout << "\n\tEmployee Deleted Successfully!\n";
            return temp;
        }
        else if (node->right == nullptr) {
            Employee* temp = node->left;
            delete node;
            cout << "\n\tEmployee Deleted Successfully!\n";
            return temp;
        }

        Employee* successor = node->right;
        while (successor->left != nullptr)
            successor = successor->left;

        node->id = successor->id;
        node->name = successor->name;
        node->department = successor->department;
        node->salary = successor->salary;

        node->right = deleteNode(node->right, successor->id);
    }

    return node;
}

// Generate Salary Slip
void generateSalarySlip() {
    int id;
    cout << "\n\tEnter Employee ID for Salary Slip: ";
    id = getValidatedInput();

    Employee* emp = findEmployeeById(root, id);
    if (emp) {
        cout << "\n\t================ Salary Slip =================\n";
        cout << "\tEmployee ID: " << emp->id << endl;
        cout << "\tName: " << emp->name << endl;
        cout << "\tDepartment: " << emp->department << endl;
        cout << "\tSalary: $" << fixed << setprecision(2) << emp->salary << endl;
        cout << "\t============================================\n";
    }
    else {
        cout << "\n\tEmployee Not Found.\n";
    }
}

// Define a custom Queue structure
struct QueueNode {
    Employee* emp;
    QueueNode* next;
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;

    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(Employee* emp) {
        QueueNode* newNode = new QueueNode;
        newNode->emp = emp;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Employee* dequeue() {
        if (front == nullptr) {
            return nullptr;
        }

        QueueNode* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        Employee* emp = temp->emp;
        delete temp;
        return emp;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// Main Menu
void mainMenu() {
    int choice;
    do {
        cout << "\n\t================ Employee Management System =================\n";
        cout << "\t1. Insert Employee\n";
        cout << "\t2. Display All Employees\n";
        cout << "\t3. Search Employee\n";
        cout << "\t4. Edit Employee\n";
        cout << "\t5. Delete Employee\n";
        cout << "\t6. Generate Salary Slip\n";
        cout << "\t7. Exit\n";
        cout << "\tEnter your choice: ";
        choice = getValidatedInput();

        switch (choice) {
        case 1:
            insertEmployee();
            break;
        case 2:
            cout << "\n\tEmployee Details:\n";
            displayTableHeader();
            displayEmployees(root);
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            editEmployee();
            break;
        case 5:
            deleteEmployee();
            break;
        case 6:
            generateSalarySlip();
            break;
        case 7:
            cout << "\n\tExiting System. Goodbye!\n";
            break;
        default:
            cout << "\n\tInvalid choice! Please select a valid option.\n";
        }
    } while (choice != 7);
}

// Main Function
int main() {
    adminLogin();
    return 0;
}
