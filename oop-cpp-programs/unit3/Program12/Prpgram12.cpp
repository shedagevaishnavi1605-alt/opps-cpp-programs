#include <iostream>                         // Includes input/output library
#include <vector>                           // Includes vector library

class Shape {                               // Defines the base class

public:
    virtual double area() const = 0;        // Pure virtual function for area

    virtual ~Shape() = default;             // Virtual destructor
};

class Rectangle : public Shape {            // Rectangle inherits from Shape

private:
    double width;                           // Stores width
    double height;                          // Stores height

public:
    Rectangle(double width, double height)  // Constructor
        : width(width), height(height) {}   // Initializes width and height

    double area() const override {           // Overrides area() function
        return width * height;               // Returns rectangle area
    }
};

class Circle : public Shape {               // Circle inherits from Shape

private:
    double radius;                          // Stores radius

public:
    Circle(double radius) : radius(radius) {} // Constructor initializes radius

    double area() const override {           // Overrides area() function
        return 3.14159 * radius * radius;   // Returns circle area
    }
};

int main() {                                // Main function: program starts here

    Rectangle rectangle(4, 5);               // Creates Rectangle object

    Circle circle(3);                        // Creates Circle object

    std::vector<Shape*> shapes = {           // Creates collection of Shape pointers
        &rectangle,                          // Stores address of Rectangle object
        &circle                              // Stores address of Circle object
    };

    for (Shape* shape : shapes) {            // Loops through all Shape pointers
        std::cout << "Area: " << shape->area() << '\n';
        // Calls the correct area() function using polymorphism
    }

    return 0;                                // Ends the program successfully
}