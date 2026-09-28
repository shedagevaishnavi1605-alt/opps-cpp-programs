#include <iostream>          // Used for input and output

using namespace std;         // Allows us to use cout directly


// Abstract base class
class Shape {

public:

    // Pure virtual function
    virtual void area() = 0;     // Makes Shape an abstract class
};


// Derived class Rectangle inherits from Shape
class Rectangle : public Shape {

private:
    int length;                  // Stores length of rectangle
    int width;                   // Stores width of rectangle

public:

    // Constructor of Rectangle class
    Rectangle(int l, int w) : length(l), width(w) {}

    // Override the pure virtual area() function
    void area() override {
        cout << "Rectangle Area: " << length * width << endl;
        // Calculate and display area of rectangle
    }
};


// Derived class Circle inherits from Shape
class Circle : public Shape {

private:
    float radius;                // Stores radius of circle

public:

    // Constructor of Circle class
    Circle(float r) : radius(r) {}

    // Override the pure virtual area() function
    void area() override {
        cout << "Circle Area: " << 3.14 * radius * radius << endl;
        // Calculate and display area of circle
    }
};


// Main function
int main() {

    // Create Rectangle object with length 10 and width 5
    Rectangle rectangle(10, 5);

    // Create Circle object with radius 7
    Circle circle(7);

    // Call area() function of Rectangle
    rectangle.area();

    // Call area() function of Circle
    circle.area();

    return 0;                  // End the program
}