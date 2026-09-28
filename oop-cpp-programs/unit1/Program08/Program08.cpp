#include <iostream>              // Includes input/output library

using namespace std;             // Allows us to use cout without std::

class Test {                     // Defines a class named Test

private:                         // Starts private section

    int value;                   // Declares a private integer variable

public:                          // Starts public section

    Test(int v) {                // Constructor receives a value

        value = v;               // Stores v in the private variable
    }

    inline int getValue() {      // Defines an inline function

        return value;            // Returns the value of private variable
    }

    friend void show(Test t);    // Declares show() as a friend function
};

void show(Test t) {              // Defines the friend function

    cout << t.value;             // Accesses the private value
}

int main() {                     // Main function: program starts here

    Test obj(50);                // Creates object and passes 50 to constructor

    cout << obj.getValue() << endl;
    // Calls inline function and displays the value

    show(obj);                   // Calls the friend function

    return 0;                    // Ends the program successfully
}