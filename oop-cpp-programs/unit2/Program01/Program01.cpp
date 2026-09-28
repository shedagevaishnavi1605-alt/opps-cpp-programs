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

    // Function to display the name
    void displayName() const {
        std::cout << "Name: " << name << '\n';   // Print name
    }
};

// Derived class inheriting from Person
class Student : public Person {
private:
    int rollNumber;          // Stores student's roll number

public:
    // Constructor of Student class
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {}

    // Function to display student details
    void displayStudent() const {
        displayName();       // Call base class function
        std::cout << "Roll Number: " << rollNumber << '\n'; // Print roll number
    }
};

// Main function
int main() {

    // Create Student object with name and roll number
    Student student("Amit", 101);

    // Display student details
    student.displayStudent();

    return 0;                // End the program
}