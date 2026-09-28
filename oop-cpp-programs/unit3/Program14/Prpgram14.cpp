#include <iostream>                         // Includes input/output library

class Base {                                // Defines the base class

public:
    int baseValue;                          // Stores base class value

    Base(int value = 0) : baseValue(value) {} // Constructor initializes baseValue

    void display() const {                  // Function to display base value
        std::cout << "Base value: " 
                  << baseValue << '\n';     // Prints base value
    }
};

class Derived : public Base {               // Derived class inherits from Base

public:
    int derivedValue;                       // Stores derived class value

    Derived(int base, int derived)           // Constructor
        : Base(base), derivedValue(derived) {} // Initializes base and derived values

    void display() const {                  // Function to display both values
        std::cout << "Base value: " 
                  << baseValue << ", Derived value: "
                  << derivedValue << '\n';  // Prints both values
    }
};

int main() {                                // Main function: program starts here

    Derived derived(10, 20);                // Creates Derived object

    Base base = derived;                    // Copies Derived into Base object
                                            // Derived-specific data is sliced off

    base.display();                         // Calls Base display function

    return 0;                               // Ends the program successfully
}