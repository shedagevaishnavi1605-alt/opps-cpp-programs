#include <iostream>              // Includes input/output library

using namespace std;             // Allows us to use cout without std::

int main() {                     // Main function: program starts here

    int marks[5] = {78, 82, 91, 67, 88};
    // Creates an array named marks and stores marks of 5 students

    for (int i = 0; i < 5; i++) {
        // Loop starts from 0 and repeats until i becomes 5

        cout << marks[i] << " ";
        // Displays each element of the marks array
    }

    return 0;                    // Ends the program successfully
}