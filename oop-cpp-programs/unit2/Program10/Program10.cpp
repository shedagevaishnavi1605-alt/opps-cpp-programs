#include <iostream>          // Used for input and output

using namespace std;         // Allows us to use cout directly


// Base class
class Vehicle {

public:

    // Virtual function
    virtual void move() {
        cout << "Vehicle is moving" << endl;   // Display base class message
    }
};


// Derived class Car inherits from Vehicle
class Car : public Vehicle {

public:

    // Override the move() function of Vehicle class
    void move() override {
        cout << "Car is moving" << endl;       // Display car message
    }
};


// Derived class Boat inherits from Vehicle
class Boat : public Vehicle {

public:

    // Override the move() function of Vehicle class
    void move() override {
        cout << "Boat is moving" << endl;      // Display boat message
    }
};


// Main function
int main() {

    // Create a Car object
    Car car;

    // Create a Boat object
    Boat boat;

    // Call Car's overridden move() function
    car.move();

    // Call Boat's overridden move() function
    boat.move();

    return 0;                  // End the program
}