#include <iostream>          // Used for input and output
#include <string>            // Used for string data type

using namespace std;         // Allows us to use cout and string directly


// Base class
class Vehicle {

protected:
    string registrationNumber;    // Stores vehicle registration number

public:

    // Constructor of Vehicle class
    Vehicle(string regNo) : registrationNumber(regNo) {}

    // Function to start the vehicle
    void start() {
        cout << "Vehicle started" << endl;    // Display vehicle started message
    }
};


// Derived class 1: Car inherits from Vehicle
class Car : public Vehicle {

public:

    // Constructor of Car class
    Car(string regNo) : Vehicle(regNo) {}

    // Function to open car boot
    void openBoot() {
        cout << "Car boot opened" << endl;    // Display boot opened message
    }
};


// Derived class 2: Bike inherits from Vehicle
class Bike : public Vehicle {

public:

    // Constructor of Bike class
    Bike(string regNo) : Vehicle(regNo) {}

    // Function to remind about helmet
    void helmetReminder() {
        cout << "Wear a helmet" << endl;      // Display helmet reminder
    }
};


// Main function
int main() {

    // Create a Car object with registration number
    Car car("MH12AB1234");

    // Create a Bike object with registration number
    Bike bike("MH12CD5678");

    // Start the car
    car.start();

    // Open the car boot
    car.openBoot();

    // Start the bike
    bike.start();

    // Display helmet reminder
    bike.helmetReminder();

    return 0;                  // End the program
}