#include <iostream>                         // Includes input/output library

class Payment {                             // Defines abstract Payment class

public:
    virtual void pay(double amount) = 0;    // Pure virtual function for payment

    virtual ~Payment() = default;           // Virtual destructor
};

class CreditCardPayment : public Payment {  // CreditCardPayment inherits Payment

public:
    void pay(double amount) override {      // Implements the pay() function
        std::cout << "Paid " << amount
                  << " using Credit Card\n"; // Displays payment details
    }
};

class UPIPayment : public Payment {         // UPIPayment inherits Payment

public:
    void pay(double amount) override {      // Implements the pay() function
        std::cout << "Paid " << amount
                  << " using UPI\n";        // Displays payment details
    }
};

int main() {                                // Main function: program starts here

    CreditCardPayment card;                 // Creates Credit Card payment object

    UPIPayment upi;                         // Creates UPI payment object

    Payment* payment1 = &card;              // Base pointer points to card object

    Payment* payment2 = &upi;               // Base pointer points to UPI object

    payment1->pay(1000);                    // Calls Credit Card payment at run time

    payment2->pay(500);                     // Calls UPI payment at run time

    return 0;                               // Ends the program successfully
}