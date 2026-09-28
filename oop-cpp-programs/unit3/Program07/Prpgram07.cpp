#include <iostream>                         // Includes input/output library

class Number {                              // Defines a class named Number

private:
    int value;                              // Stores the number

public:
    Number(int value = 0) : value(value) {} // Constructor initializes value

    friend Number operator+(const Number& first,
                            const Number& second); // Declares + as friend function

    void display() const {                  // Function to display the value
        std::cout << "Value: " << value << '\n'; // Prints the value
    }
};

Number operator+(const Number& first,
                 const Number& second) {   // Defines + operator outside the class

    return Number(first.value + second.value); // Adds private values and returns object
}

int main() {                                // Main function: program starts here

    Number first(10);                       // Creates first Number object

    Number second(20);                      // Creates second Number object

    Number result = first + second;         // Uses overloaded + operator

    result.display();                       // Displays the result

    return 0;                               // Ends the program successfully
}