#include <iostream>              // Includes input/output library

using namespace std;             // Allows us to use cout without std::

int add(int, int);               // Function prototype for add function

int main() {                     // Main function: program starts here

    int a = 10, b = 20;           // Declares two integer variables

    cout << "Sum = " << add(a, b) << endl;
    // Calls add function with a and b and displays the result

    return 0;                     // Ends the program successfully
}

int add(int x, int y) {           // Defines the add function

    return x + y;                 // Adds x and y and returns the result
}