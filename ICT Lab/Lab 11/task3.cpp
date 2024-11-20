#include <iostream>
#include <string>
using namespace std;

// Base class Employee
class Employee {
protected:
    string name;
    double salary;
public:
    Employee(string empName, double empSalary) : name(empName), salary(empSalary) {}
    virtual double calculateEarnings() const = 0;
    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "Base Salary: $" << salary << endl;
    }
    virtual ~Employee() {}
};
class Manager : public Employee {
private:
    double bonus;
public:
    Manager(string empName, double empSalary, double empBonus)
        : Employee(empName, empSalary), bonus(empBonus) {}
    double calculateEarnings() const override {
        return salary + bonus;
    }
    void display() const override {
        Employee::display();
        cout << "Bonus: $" << bonus << endl;
        cout << "Total Earnings: $" << calculateEarnings() << endl;
    }
};
class Intern : public Employee {
private:
    double hoursWorked;
    double hourlyRate;
public:
    Intern(string empName, double empSalary, double empHoursWorked, double empHourlyRate)
        : Employee(empName, empSalary), hoursWorked(empHoursWorked), hourlyRate(empHourlyRate) {}
    double calculateEarnings() const override {
        return hoursWorked * hourlyRate;
    }
    void display() const override {
        Employee::display();
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Total Earnings: $" << calculateEarnings() << endl;
    }
};
int main() {
    Manager manager("Alice Johnson", 120, 200);
    Intern intern("Jake James", 0, 48, 15);
    cout << "\n--- Manager Details ---" << endl;
    manager.display();
    cout << "\n--- Intern Details ---" << endl;
    intern.display();
    return 0;
}
