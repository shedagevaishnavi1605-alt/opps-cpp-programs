#include <iostream>                         // Includes input/output library

class Shape {                               // Defines the abstract base class

public:
    virtual double area() const = 0;        // Pure virtual function

    virtual ~Shape() = default;             // Virtual destructor
};

class Rectangle : public Shape {            // Rectangle inherits from Shape

private:
    double width;                           // Stores width of rectangle
    double height;                          // Stores height of rectangle

public:
    Rectangle(double width, double height)  // Constructor
        : width(width), height(height) {}   // Initializes width and height

    double area() const override {          // Implements the pure virtual function
        return width * height;              // Returns area of rectangle
    }
};

int main() {                                // Main function: program starts here

    Rectangle rectangle(5, 4);              // Creates Rectangle object

    Shape* shape = &rectangle;              // Base pointer points to Rectangle object

    std::cout << "Area: " << shape->area() << '\n';
    // Calls Rectangle's area() through the base pointer

    return 0;                               // Ends the program successfully
}