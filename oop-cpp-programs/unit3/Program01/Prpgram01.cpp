#include <iostream>                    // Includes input/output library

int add(int first, int second) {       // Function to add two integers

    return first + second;             // Returns the sum of two integers
}

double add(double first, double second) {  // Function to add two decimal numbers

    return first + second;             // Returns the sum of two decimal numbers
}

int add(int first, int second, int third) {  // Function to add three integers

    return first + second + third;     // Returns the sum of three integers
}

int main() {                           // Main function: program starts here

    std::cout << "Sum of two integers: " << add(10, 20) << '\n';
    // Calls add(int, int) and displays the result

    std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';
    // Calls add(double, double) and displays the result

    std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';
    // Calls add(int, int, int) and displays the result

    return 0;                          // Ends the program successfully
}