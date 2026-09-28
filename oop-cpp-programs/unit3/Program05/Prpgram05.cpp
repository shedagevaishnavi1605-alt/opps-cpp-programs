#include <iostream>                         // Includes input/output library

class Complex {                             // Defines a class named Complex

private:
    double real;                            // Stores real part
    double imag;                            // Stores imaginary part

public:
    Complex(double real = 0, double imag = 0) // Constructor
        : real(real), imag(imag) {}          // Initializes real and imaginary parts

    Complex operator+(const Complex& other) const { // Overloads + operator
        return Complex(real + other.real,          // Adds real parts
                       imag + other.imag);          // Adds imaginary parts
    }

    void display() const {                  // Function to display complex number
        std::cout << real << " + " << imag << "i\n"; // Prints complex number
    }
};

int main() {                                // Main function: program starts here

    Complex first(2, 3);                    // Creates first complex number: 2 + 3i

    Complex second(4, 5);                   // Creates second complex number: 4 + 5i

    Complex result = first + second;        // Adds two complex numbers using + operator

    result.display();                       // Displays the result

    return 0;                               // Ends the program successfully
}