#include <iostream>          // Used for input and output

// Base class
class Base {
public:
    // Public function of the base class
    void show() const {
        std::cout << "Base public function\n";   // Display message
    }
};

// Derived class using public inheritance
class PublicDerived : public Base {
    // Base public members remain public
};

// Derived class using private inheritance
class PrivateDerived : private Base {
public:
    // Function to call the base class function
    void callBaseShow() const {
        show();                  // Call inherited show() function
    }
};

// Main function
int main() {

    // Create object of PublicDerived
    PublicDerived publicObject;

    // Access base class public function directly
    publicObject.show();

    // Create object of PrivateDerived
    PrivateDerived privateObject;

    // Access base class function through derived class function
    privateObject.callBaseShow();

    // privateObject.show();
    // Error because show() is private through private inheritance

    return 0;                    // End the program
}