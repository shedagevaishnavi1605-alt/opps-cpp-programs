#include <iostream>          // Used for input and output

using namespace std;         // Allows us to use cout directly


// Account class
class Account {

private:
    double balance;          // Stores account balance

public:

    // Constructor of Account class
    Account(double amount) {
        balance = amount;    // Assign amount to balance
    }

    // Declare Auditor as a friend class
    friend class Auditor;
};


// Auditor class
class Auditor {

public:

    // Function to check account balance
    void checkBalance(Account account) {

        // Access private balance of Account class
        cout << "Account Balance: " << account.balance << endl;
    }
};


// Main function
int main() {

    // Create an Account object with balance 50000
    Account account(50000);

    // Create an Auditor object
    Auditor auditor;

    // Auditor checks the account balance
    auditor.checkBalance(account);

    return 0;                  // End the program
}