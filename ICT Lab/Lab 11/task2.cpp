#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double grade;
public:
    void setName(string studentName) {
        name = studentName;
    }
    void setRollNumber(int rollNum) {
        rollNumber = rollNum;
    }
    void setGrade(double studentGrade) {
        if (studentGrade >= 0 && studentGrade <= 100) {
            grade = studentGrade;
        } else {
            cout << "Invalid grade! Please enter a value between 0 and 100." << endl;
            grade = 0; // Default to 0 if invalid
        }
    }
    string getName() const {
        return name;
    }
    int getRollNumber() const {
        return rollNumber;
    }
    double getGrade() const {
        return grade;
    }
    bool hasPassed() const {
        return grade >= 50;
    }
};

int main() {
    Student student;
    string name;
    int rollNumber;
    double grade;

    cout << "Enter student's name: ";
    getline(cin, name);
    student.setName(name);

    cout << "Enter roll number: ";
    cin >> rollNumber;
    student.setRollNumber(rollNumber);

    cout << "Enter grade: ";
    cin >> grade;
    student.setGrade(grade);
    cout << "\n**** Student Details ****" << endl;
    cout << "Name: " << student.getName() << endl;
    cout << "Roll Number: " << student.getRollNumber() << endl;
    cout << "Grade: " << student.getGrade() << endl;
    if (student.hasPassed()) {
        cout << "Status: Passed" << endl;
    } else {
        cout << "Status: Failed" << endl;
    }
    return 0;
}
