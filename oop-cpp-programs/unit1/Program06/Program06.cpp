#include <iostream>              // Includes input/output library

using namespace std;             // Allows us to use cout without std::

class Demo {                     // Defines a class named Demo

public:                          // Makes the following members accessible

    Demo() {                     // Constructor: runs when object is created

        cout << "Constructor called" << endl;
        // Displays a message when constructor is called
    }

    ~Demo() {                    // Destructor: runs when object is destroyed

        cout << "Destructor called" << endl;
        // Displays a message when destructor is called
    }
};

int main() {                     // Main function: program starts here

    Demo d;                      // Creates an object d of Demo class

    return 0;                    // Ends main and object cleanup occurs
}