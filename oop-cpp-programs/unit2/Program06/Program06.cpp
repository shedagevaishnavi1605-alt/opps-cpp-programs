#include <iostream>          // Used for input and output

using namespace std;         // Allows us to use cout directly


// First base class
class Academic {

public:

    // Function to display academic marks
    void academicMarks() {
        cout << "Academic Marks: 80" << endl;   // Display academic marks
    }
};


// Second base class
class Sports {

public:

    // Function to display sports marks
    void sportsMarks() {
        cout << "Sports Marks: 15" << endl;     // Display sports marks
    }
};


// Student inherits from both Academic and Sports
class Student : public Academic, public Sports {

public:

    // Function to display total marks
    void totalMarks() {

        academicMarks();       // Call function from Academic class
        sportsMarks();         // Call function from Sports class

        cout << "Total Marks: 95" << endl;      // Display total marks
    }
};


// Main function
int main() {

    // Create an object of Student class
    Student student;

    // Display all marks
    student.totalMarks();

    return 0;                  // End the program
}