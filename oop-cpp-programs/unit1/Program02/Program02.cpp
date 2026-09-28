#include <iostream>              // Includes input/output library

using namespace std;             // Allows us to use cout without std::

int main() {                     // Main function: program starts here

    int marks = 45;               // Stores the student's marks

    if (marks >= 40) {            // Checks if marks are 40 or more

        cout << "Pass";           // Displays Pass if condition is true

    } else {                      // Runs when the if condition is false

        cout << "Fail";           // Displays Fail if marks are below 40
    }

    return 0;                     // Ends the program successfully
}