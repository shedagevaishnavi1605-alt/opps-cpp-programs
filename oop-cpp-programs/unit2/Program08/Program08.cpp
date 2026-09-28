#include <iostream>          // Used for input and output

using namespace std;         // Allows us to use cout directly


// Base class
class Base {

public:

    // Constructor of Base class
    Base() {
        cout << "Base constructor" << endl;    // Display constructor message
    }

    // Destructor of Base class
    ~Base() {
        cout << "Base destructor" << endl;     // Display destructor message
    }
};


// Derived class inherits from Base
class Derived : public Base {

public:

    // Constructor of Derived class
    Derived() {
        cout << "Derived constructor" << endl; // Display constructor message
    }

    // Destructor of Derived class
    ~Derived() {
        cout << "Derived destructor" << endl;  // Display destructor message
    }
};


// Main function
int main() {

    // Create an object of Derived class
    Derived obj;

    return 0;                  // End the program
}