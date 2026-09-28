#include <iostream>                         // Includes input/output library

class Counter {                             // Defines a class named Counter

private:
    int value;                              // Stores the counter value

public:
    Counter(int value = 0) : value(value) {} // Constructor initializes value

    Counter& operator++() {                 // Overloads prefix ++ operator
        ++value;                            // Increases value by 1
        return *this;                       // Returns the current object
    }

    Counter operator++(int) {               // Overloads postfix ++ operator
        Counter old = *this;                // Stores the old value
        ++value;                            // Increases value by 1
        return old;                         // Returns the old value
    }

    void display() const {                  // Function to display value
        std::cout << "Value: " << value << '\n'; // Prints the value
    }
};

int main() {                                // Main function: program starts here

    Counter counter(5);                     // Creates Counter object with value 5

    ++counter;                              // Calls prefix increment operator
    counter.display();                      // Displays updated value

    Counter old = counter++;               // Calls postfix increment operator
    old.display();                         // Displays old value
    counter.display();                      // Displays new value

    return 0;                               // Ends the program successfully
}