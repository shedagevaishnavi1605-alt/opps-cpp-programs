#include <iostream>          // Used for input and output
#include <string>            // Used for string data type

using namespace std;         // Allows us to use cout and string directly


// Abstract base class
class Employee {

protected:
    string name;             // Stores employee name

public:

    // Constructor of Employee class
    Employee(string employeeName)
        : name(employeeName) {
    }

    // Pure virtual function
    virtual void displayPaySlip() = 0;
    // Makes Employee an abstract class
};


// Derived class for permanent employees
class PermanentEmployee : public Employee {

private:
    double salary;           // Stores permanent employee salary

public:

    // Constructor of PermanentEmployee class
    PermanentEmployee(string employeeName, double employeeSalary)
        : Employee(employeeName), salary(employeeSalary) {
    }

    // Override displayPaySlip() function
    void displayPaySlip() override {

        cout << "Permanent Employee" << endl;
        // Display employee type

        cout << "Name: " << name << endl;
        // Display employee name

        cout << "Salary: " << salary << endl;
        // Display employee salary
    }
};


// Derived class for contract employees
class ContractEmployee : public Employee {

private:
    double hourlyRate;        // Stores hourly payment rate
    int hours;                // Stores number of working hours

public:

    // Constructor of ContractEmployee class
    ContractEmployee(string employeeName,
                     double rate, int workingHours)
        : Employee(employeeName),
          hourlyRate(rate),
          hours(workingHours) {
    }

    // Override displayPaySlip() function
    void displayPaySlip() override {

        cout << "Contract Employee" << endl;
        // Display employee type

        cout << "Name: " << name << endl;
        // Display employee name

        cout << "Pay: " << hourlyRate * hours << endl;
        // Calculate and display total pay
    }
};


// Main function
int main() {

    // Create a PermanentEmployee object
    PermanentEmployee permanent("Amit", 50000);

    // Create a ContractEmployee object
    ContractEmployee contract("Neha", 500, 80);

    // Display permanent employee pay slip
    permanent.displayPaySlip();

    // Display contract employee pay slip
    contract.displayPaySlip();

    return 0;                  // End the program
}