#include <iostream>              // Includes input/output library

using namespace std;             // Allows us to use cout without std::

class Student {                  // Defines a class named Student

public:                          // Starts the public section

    static int count;            // Declares a static variable shared by all objects

    Student() {                  // Constructor runs whenever an object is created

        count++;                 // Increases count by 1
    }
};

int Student::count = 0;          // Initializes the static variable to 0

int main() {                     // Main function: program starts here

    Student s1, s2, s3;           // Creates three Student objects

    cout << Student::count;       // Displays the total number of objects

    return 0;                    // Ends the program successfully
}