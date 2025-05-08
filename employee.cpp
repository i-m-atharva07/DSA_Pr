#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void addEmployee() {
    ofstream f;
    f.open("db.txt", ios::app);

    string empID, name, designation, salary;
    cout << "Enter Employee ID: ";
    cin >> empID;
    cout << "Enter Employee Name: ";
    cin >> name;
    cout << "Enter Designation: ";
    cin >> designation;
    cout << "Enter Salary: ";
    cin >> salary;

    f << left << setw(20) << empID << setw(20) << name
      << setw(20) << designation << setw(20) << salary << endl;

    f.close();

    cout << "Employee added successfully.\n";
}

void deleteEmployee() {
    ifstream f;
    f.open("db.txt");

    string line, empID;
    cout << "Enter Employee ID to delete: ";
    cin >> empID;

    string fileData;
    bool found = false;

    while (getline(f, line)) {
        if (line.find("Employee ID") != string::npos) {
            fileData += line + "\n"; // keep header
            continue;
        }

        if (line.find(empID) == string::npos) {
            fileData += line + "\n";
        } else {
            found = true;
        }
    }
    f.close();

    ofstream f1;
    f1.open("db.txt", ios::out);
    f1 << fileData;
    f1.close();

    if (found)
        cout << "Employee deleted successfully.\n";
    else
        cout << "Employee not found.\n";
}

void searchEmployee() {
    ifstream f;
    f.open("db.txt");

    string line, empID;
    cout << "Enter Employee ID to search: ";
    cin >> empID;

    bool found = false;

    while (getline(f, line)) {
        if (line.find(empID) != string::npos && line.find("Employee ID") == string::npos) {
            cout << "\nEmployee Details:\n" << line << endl;
            found = true;
            break;
        }
    }
    f.close();

    if (!found)
        cout << "Employee not found.\n";
}

void printEmployees() {
    ifstream f;
    f.open("db.txt");

    string line;
    cout << "\n--- Employee Records ---\n";
    while (getline(f, line)) {
        cout << line << endl;
    }
    f.close();
}

int main() {
    ofstream f;
    f.open("db.txt", ios::out);
    f << left << setw(20) << "Employee ID" << setw(20) << "Name"
      << setw(20) << "Designation" << setw(20) << "Salary" << endl;
    f.close();

    int choice;
    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Print All Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            printEmployees();
            break;
        case 5:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
