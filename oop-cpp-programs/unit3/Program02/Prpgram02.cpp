#include <iostream>                         // Includes input/output library

double area(int side) {                     // Function to calculate area of square
    return side * side;                     // Returns side × side
}

double area(int length, int breadth) {      // Function to calculate area of rectangle
    return length * breadth;                // Returns length × breadth
}

double area(double radius) {                // Function to calculate area of circle
    return 3.14159 * radius * radius;       // Returns π × radius × radius
}

int main() {                                // Main function: program starts here

    std::cout << "Square area: " 
              << area(5) << '\n';           // Calls area(int) for square

    std::cout << "Rectangle area: " 
              << area(6, 4) << '\n';        // Calls area(int, int) for rectangle

    std::cout << "Circle area: " 
              << area(3.0) << '\n';         // Calls area(double) for circle

    return 0;                               // Ends the program successfully
}