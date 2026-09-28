#include <iostream>                         // Includes input/output library

class Distance {                            // Defines a class named Distance

private:
    int meters;                             // Stores distance in meters

public:
    Distance(int meters = 0) : meters(meters) {} // Constructor initializes meters

    bool operator<(const Distance& other) const { // Overloads < operator
        return meters < other.meters;       // Compares two distances
    }

    void display() const {                  // Function to display distance
        std::cout << meters << " meters\n"; // Prints distance
    }
};

int main() {                                // Main function: program starts here

    Distance first(10);                     // Creates first distance: 10 meters

    Distance second(15);                    // Creates second distance: 15 meters

    first.display();                        // Displays first distance

    second.display();                       // Displays second distance

    if (first < second) {                   // Uses overloaded < operator
        std::cout << "First distance is smaller.\n"; // Displays comparison result
    }

    return 0;                               // Ends the program successfully
}