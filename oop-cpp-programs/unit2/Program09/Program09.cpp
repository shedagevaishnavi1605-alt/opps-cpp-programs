#include <iostream>          // Used for input and output
#include <string>            // Used for string data type

using namespace std;         // Allows us to use cout and string directly


// Base class
class Person {

protected:
    string name;             // Stores the person's name
    int age;                 // Stores the person's age

public:

    // Parameterized constructor of Person class
    Person(string personName, int personAge)
        : name(personName), age(personAge) {
    }
};


// Derived class inherits from Person
class Student : public Person {

public:

    // Constructor of Student class
    // It passes name and age to the Person constructor
    Student(string studentName, int studentAge)
        : Person(studentName, studentAge) {
    }

    // Function to display student details
    void display() {
        cout << "Name: " << name << endl;    // Display student's name
        cout << "Age: " << age << endl;      // Display student's age
    }
};


// Main function
int main() {

    // Create Student object
    // Name = Kiran and Age = 24
    Student student("Kiran", 24);

    // Display student details
    student.display();

    return 0;                  // End the program
}