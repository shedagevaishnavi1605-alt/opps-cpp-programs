#include <iostream>          // Used for input and output
#include <string>            // Used for string data type

using namespace std;         // Allows us to use cout and string directly


// Base class
class Person {

protected:
    string name;             // Stores person's name

public:

    // Function to set the person's name
    void setName(string personName) {
        name = personName;   // Assign name to the data member
    }

    // Function to display the person's name
    void displayName() {
        cout << "Name: " << name << endl;   // Display name
    }
};


// Student virtually inherits from Person
class Student : virtual public Person {

};


// Employee virtually inherits from Person
class Employee : virtual public Person {

};


// TeachingAssistant inherits from both Student and Employee
class TeachingAssistant : public Student, public Employee {

public:

    // Function to display teaching assistant details
    void display() {
        displayName();       // Call Person's displayName() function
    }
};


// Main function
int main() {

    // Create an object of TeachingAssistant
    TeachingAssistant ta;

    // Set the name using the single shared Person object
    ta.setName("Rahul");

    // Display the name
    ta.display();

    return 0;                // End the program
}