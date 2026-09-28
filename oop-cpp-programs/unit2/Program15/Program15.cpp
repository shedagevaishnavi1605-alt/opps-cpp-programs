#include <iostream>          // Used for input and output
#include <string>            // Used for string data type

using namespace std;         // Allows us to use cout and string directly


// Base class
class Vehicle {

protected:
    string vehicleNumber;    // Stores vehicle registration number
    double ratePerDay;       // Stores rental rate per day

public:

    // Constructor of Vehicle class
    Vehicle(string number, double rate)
        : vehicleNumber(number), ratePerDay(rate) {
    }

    // Virtual function to calculate rent
    virtual double calculateRent(int days) {
        return ratePerDay * days;    // Calculate basic rent
    }

    // Function to display vehicle details
    virtual void display() {
        cout << "Vehicle Number: " << vehicleNumber << endl;
        // Display vehicle number

        cout << "Rate per Day: " << ratePerDay << endl;
        // Display rental rate per day
    }
};


// Car class inherits from Vehicle
class Car : public Vehicle {

public:

    // Constructor of Car class
    Car(string number, double rate)
        : Vehicle(number, rate) {
    }

    // Override calculateRent() function
    double calculateRent(int days) override {
        return ratePerDay * days + 500;
        // Calculate car rent with additional charge
    }

    // Override display() function
    void display() override {
        cout << "Car" << endl;             // Display vehicle type
        Vehicle::display();                // Display vehicle details
    }
};


// Bike class inherits from Vehicle
class Bike : public Vehicle {

public:

    // Constructor of Bike class
    Bike(string number, double rate)
        : Vehicle(number, rate) {
    }

    // Override calculateRent() function
    double calculateRent(int days) override {
        return ratePerDay * days + 200;
        // Calculate bike rent with additional charge
    }

    // Override display() function
    void display() override {
        cout << "Bike" << endl;            // Display vehicle type
        Vehicle::display();                // Display vehicle details
    }
};


// Main function
int main() {

    // Create a Car object
    Car car("MH12AB1234", 1500);

    // Create a Bike object
    Bike bike("MH12CD5678", 500);

    // Number of rental days
    int days = 3;

    // Display car details
    car.display();

    // Display car rental amount
    cout << "Car Rent: " << car.calculateRent(days) << endl;

    // Display bike details
    bike.display();

    // Display bike rental amount
    cout << "Bike Rent: " << bike.calculateRent(days) << endl;

    return 0;                  // End the program
}