#include <iostream>              // Includes input/output library

using namespace std;             // Allows us to use cout without std::

class Student {                  // Defines a class named Student

public:                          // Makes the following members accessible

    string name;                 // Declares a string variable for student name

    int age;                     // Declares an integer variable for student age

    void show() {                // Defines a member function named show

        cout << name << " " << age << endl;
        // Displays the student's name and age
    }
};

int main() {                     // Main function: program starts here

    Student s1;                  // Creates an object s1 of Student class

    s1.name = "Amit";            // Assigns "Amit" to the name

    s1.age = 20;                 // Assigns 20 to the age

    s1.show();                   // Calls show() function using the object

    return 0;                    // Ends the program successfully
}