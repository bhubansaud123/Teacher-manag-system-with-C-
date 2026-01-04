
#include <iostream>
#include <vector>
using namespace std;

// -------------------- Teacher Class --------------------
class Teacher {
private:
    int id;
    string name;
    string subject;
    int experience;      // in years
    double baseSalary;

public:
    Teacher(int i, string n, string s, int e, double b)
        : id(i), name(n), subject(s), experience(e), baseSalary(b) {}

    int getId() const {
        return id;
    }

    double calculateSalary() const {
        // Bonus based on experience
        return baseSalary + (experience * 2000);
    }

    void display() const {
        cout << "Teacher ID   : " << id << endl;
        cout << "Name         : " << name << endl;
        cout << "Subject      : " << subject << endl;
        cout << "Experience   : " << experience << " years" << endl;
        cout << "Total Salary : " << calculateSalary() << endl;
        cout << "-------------------------------\n";
    }
};

// -------------------- School Class --------------------
class School {
private:
    vector<Teacher> teachers;

public:
    void addTeacher() {
        int id, exp;
        string name, subject;
        double salary;

        cout << "Enter Teacher ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Subject: ";
        getline(cin, subject);

        cout << "Enter Experience (years): ";
        cin >> exp;

        cout << "Enter Base Salary: ";
        cin >> salary;

        teachers.emplace_back(id, name, subject, exp, salary);
        cout << "Teacher added successfully!\n";
    }

    void displayAllTeachers() const {
        if (teachers.empty()) {
            cout << "No teachers available.\n";
            return;
        }

        for (const auto &t : teachers) {
            t.display();
        }
    }

    void searchTeacher() const {
        int id;
        cout << "Enter Teacher ID to search: ";
        cin >> id;

        for (const auto &t : teachers) {
            if (t.getId() == id) {
                t.display();
                return;
            }
        }
        cout << "Teacher not found!\n";
    }
};

// -------------------- Main Function --------------------
int main() {
    School school;
    int choice;

    do {
        cout << "\n====== Teacher Management System ======\n";
        cout << "1. Add Teacher\n";
        cout << "2. Display All Teachers\n";
        cout << "3. Search Teacher\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: school.addTeacher(); break;
            case 2: school.displayAllTeachers(); break;
            case 3: school.searchTeacher(); break;
            case 4: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}


// # Teacher Management System (Advanced OOP in C++)

// ## 📌 Description
// This project is a console-based Teacher Management System developed using
// Object-Oriented Programming principles in C++.
// It efficiently manages teacher records and salary calculation.

// ## 🧠 OOP Concepts Implemented
// - Class and Object
// - Encapsulation
// - Abstraction
// - Composition
// - Constructor usage
// - STL (vector)

// ## 🚀 Features
// - Add teacher details
// - Calculate salary based on experience
// - Display all teachers
// - Search teacher by ID
// - Menu-driven interface

// ## 🛠 Technologies Used
// - C++
// - Standard Template Library (STL)

// ## ▶️ How to Run
// ```bash
// g++ main.cpp -o teacher
// ./teacher
