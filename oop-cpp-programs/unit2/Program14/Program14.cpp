#include <iostream>          // Used for input and output

using namespace std;         // Allows us to use cout directly


// Outer class
class University {

public:

    // Nested class inside University
    class Department {

    public:

        // Function to display department name
        void display() {
            cout << "Department: AI & DS" << endl;
            // Display department name
        }
    };
};


// Main function
int main() {

    // Create an object of the nested Department class
    University::Department department;

    // Call display() function
    department.display();

    return 0;                // End the program
}