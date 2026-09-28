#include <iostream>                    // Includes input/output library

class Number {                         // Defines a class named Number

private:
    int value;                         // Stores the number

public:
    Number(int value) : value(value) {} // Constructor initializes value

    Number operator-() const {         // Overloads unary minus (-) operator
        return Number(-value);          // Returns a new object with negative value
    }

    void display() const {             // Function to display the number
        std::cout << "Value: " << value << '\n'; // Prints the value
    }
};

int main() {                           // Main function: program starts here

    Number original(10);               // Creates object with value 10

    Number negated = -original;        // Applies unary minus operator

    original.display();                // Displays original value

    negated.display();                 // Displays negative value

    return 0;                          // Ends the program successfully
}