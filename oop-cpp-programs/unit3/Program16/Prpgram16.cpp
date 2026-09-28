#include <iostream>                         // Includes input/output library
#include <vector>                           // Includes vector library
#include <memory>                           // Includes smart pointer library

class Employee {                            // Defines abstract Employee class

public:
    virtual double calculatePay() const = 0; // Pure virtual function

    virtual void display() const = 0;       // Pure virtual display function

    virtual ~Employee() = default;          // Virtual destructor
};

class SalariedEmployee : public Employee {  // Derived class for salaried employee

private:
    double monthlySalary;                   // Stores monthly salary

public:
    SalariedEmployee(double salary)         // Constructor
        : monthlySalary(salary) {}          // Initializes salary

    double calculatePay() const override {  // Implements calculatePay()
        return monthlySalary;               // Returns monthly salary
    }

    void display() const override {         // Implements display()
        std::cout << "Salaried Employee: "
                  << calculatePay() << '\n'; // Displays salary
    }
};

class HourlyEmployee : public Employee {    // Derived class for hourly employee

private:
    double hours;                            // Stores working hours
    double rate;                             // Stores hourly rate

public:
    HourlyEmployee(double hours, double rate) // Constructor
        : hours(hours), rate(rate) {}        // Initializes hours and rate

    double calculatePay() const override {  // Implements calculatePay()
        return hours * rate;                // Calculates hourly payment
    }

    void display() const override {         // Implements display()
        std::cout << "Hourly Employee: "
                  << calculatePay() << '\n'; // Displays payment
    }
};

int main() {                                // Main function: program starts here

    std::vector<std::unique_ptr<Employee>> employees;
    // Creates a collection of Employee pointers

    employees.push_back(
        std::make_unique<SalariedEmployee>(50000));
    // Adds a salaried employee with salary 50000

    employees.push_back(
        std::make_unique<HourlyEmployee>(160, 250));
    // Adds an hourly employee: 160 hours × 250 rate

    for (const auto& employee : employees) {
        // Loops through all employees

        employee->display();
        // Calls the correct display() function using polymorphism
    }

    return 0;                               // Ends the program successfully
}