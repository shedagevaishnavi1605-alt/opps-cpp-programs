#include <iostream>                         // Includes input/output library

class Base {                                // Defines the base class

public:
    virtual void show() {                   // Virtual function in Base class
        std::cout << "Base::show()\n";      // Displays Base class message
    }
};

class Derived : public Base {               // Derived class inherits from Base

public:
    void show() override {                  // Overrides Base's virtual function
        std::cout << "Derived::show()\n";   // Displays Derived class message
    }
};

int main() {                                // Main function: program starts here

    Derived derived;                        // Creates an object of Derived class

    Base* basePtr = &derived;               // Base pointer points to Derived object

    basePtr->show();                        // Calls Derived::show() at run time

    return 0;                               // Ends the program successfully
}