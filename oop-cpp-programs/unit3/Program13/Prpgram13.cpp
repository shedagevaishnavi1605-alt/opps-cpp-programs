#include <iostream>                         // Includes input/output library

class Base {                                // Defines the base class

public:
    virtual ~Base() {                       // Virtual destructor
        std::cout << "Base destructor\n";   // Displays Base destructor message
    }
};

class Derived : public Base {               // Derived class inherits from Base

public:
    ~Derived() {                            // Derived class destructor
        std::cout << "Derived destructor\n"; // Displays Derived destructor message
    }
};

int main() {                                // Main function: program starts here

    Base* ptr = new Derived();              // Creates Derived object using Base pointer

    delete ptr;                             // Deletes object through Base pointer

    return 0;                               // Ends the program successfully
}