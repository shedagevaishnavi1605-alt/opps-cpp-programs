#include <iostream>          // Used for input and output
#include <string>            // Used for string data type
#include <utility>           // Used for std::move()

// Base class
class Person {
protected:
    std::string name;        // Stores the person's name

public:
    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Function to display person's name
    void showPerson() const {
        std::cout << "Name: " << name << '\n';   // Display name
    }
};

// Employee inherits from Person
class Employee : public Person {
protected:
    int employeeId;          // Stores employee ID

public:
    // Constructor of Employee class
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)), employeeId(id) {}

    // Function to display employee ID
    void showEmployee() const {
        std::cout << "Employee ID: " << employeeId << '\n'; // Display ID
    }
};

// Manager inherits from Employee
class Manager : public Employee {
private:
    int teamSize;            // Stores number of team members

public:
    // Constructor of Manager class
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), teamSize(size) {}

    // Function to display manager details
    void showManager() const {
        showPerson();        // Call Person class function
        showEmployee();      // Call Employee class function
        std::cout << "Team Size: " << teamSize << '\n'; // Display team size
    }
};

// Main function
int main() {

    // Create Manager object
    Manager manager("Ravi", 501, 8);

    // Display manager details
    manager.showManager();

    return 0;                // End the program
}