#include <iostream>          // Used for input and output
#include <string>            // Used for string data type
#include <utility>           // Used for std::move()

// Base class
class Employee {
protected:
    std::string name;        // Stores the employee's name

public:
    // Constructor of Employee class
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName)) {}
};

// Derived class inheriting from Employee
class Developer : public Employee {
private:
    std::string language;     // Stores the programming language

public:
    // Constructor of Developer class
    Developer(std::string employeeName, std::string programmingLanguage)
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage)) {}

    // Function to display developer details
    void display() const {
        std::cout << "Developer: " << name << '\n';      // Display name
        std::cout << "Language: " << language << '\n';   // Display language
    }
};

// Main function
int main() {

    // Create Developer object with name and language
    Developer developer("Neha", "C++");

    // Call display function to show details
    developer.display();

    return 0;                 // End the program
}