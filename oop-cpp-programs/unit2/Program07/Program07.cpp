#include <iostream>          // Used for input and output

using namespace std;         // Allows us to use cout directly


// First base class
class Academic {

public:

    // Function with the same name as in Sports class
    void display() {
        cout << "Academic display" << endl;   // Display Academic message
    }
};


// Second base class
class Sports {

public:

    // Function with the same name as in Academic class
    void display() {
        cout << "Sports display" << endl;     // Display Sports message
    }
};


// Student inherits from both Academic and Sports
class Student : public Academic, public Sports {

public:

    // Function to display both base class functions
    void show() {

        Academic::display();     // Call display() of Academic class
        Sports::display();       // Call display() of Sports class
    }
};


// Main function
int main() {

    // Create an object of Student class
    Student student;

    // Call show() function
    student.show();

    return 0;                    // End the program
}