#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Class to represent a student
class Student {
public:
    string name;
    int id;
    vector<int> grades;

    // Constructor
    Student(string n, int i) : name(n), id(i) {}

    // Function to calculate average grade
    double calculateAverage() {
        if (grades.empty()) return 0.0;
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / grades.size();
    }

    // Function to display student details
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Grades: ";
        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << ", Average: " << calculateAverage() << endl;
    }
};

// Function to save student records to a file
void saveRecords(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Student& student : students) {
            file << student.name << " " << student.id << " ";
            for (int grade : student.grades) {
                file << grade << " ";
            }
            file << "\n";
        }
        file.close();
        cout << "Records saved to " << filename << endl;
    } else {
        cout << "Unable to open file for saving.\n";
    }
}

// Function to load student records from a file
void loadRecords(vector<Student>& students, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        students.clear();
        string name;
        int id, grade;
        while (file >> name >> id) {
            Student student(name, id);
            while (file >> grade) {
                student.grades.push_back(grade);
            }
            students.push_back(student);
            file.clear(); // Clear EOF flag
        }
        file.close();
        cout << "Records loaded from " << filename << endl;
    } else {
        cout << "Unable to open file for loading.\n";
    }
}

int main() {
    vector<Student> students;
    string filename = "student_records.txt";
    int choice;

    while (true) {
        cout << "\nStudent Grade Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Save Records to File\n";
        cout << "4. Load Records from File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id, grade;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student ID: ";
            cin >> id;
            Student student(name, id);
            cout << "Enter grades (enter -1 to stop): ";
            while (cin >> grade && grade != -1) {
                student.grades.push_back(grade);
            }
            students.push_back(student);
            cout << "Student added successfully.\n";
        } else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                for (const Student& student : students) {
                    Student::display;
                }
            }
        } else if (choice == 3) {
            saveRecords(students, filename);
        } else if (choice == 4) {
            loadRecords(students, filename);
        } else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}