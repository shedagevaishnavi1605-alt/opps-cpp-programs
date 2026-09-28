#include <iostream>                         // Includes input/output library

class Base {                                // Defines the base class

public:
    void show() {                           // Defines show() function in Base
        std::cout << "Base::show()\n";      // Displays Base class message
    }
};

class Derived : public Base {               // Defines Derived class inherited from Base

public:
    void show() {                           // Defines show() function in Derived
        std::cout << "Derived::show()\n";   // Displays Derived class message
    }
};

int main() {                                // Main function: program starts here

    Derived derived;                        // Creates an object of Derived class

    Base* basePtr = &derived;               // Base pointer points to Derived object

    basePtr->show();                        // Calls Base::show() because virtual is not used

    return 0;                               // Ends the program successfully
}