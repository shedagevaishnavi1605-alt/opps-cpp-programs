#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.
#include <sstream>      // Includes stringstream for splitting records.
#include <string>       // Includes string support.

int main() {            // Main function where program execution starts.

    std::ifstream inputFile("students.txt");
    // Opens students.txt for reading.

    if (!inputFile) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open students.txt\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Stops the program because an error occurred.
    }

    int targetRollNumber;
    // Creates a variable to store the roll number to search.

    std::cout << "Enter roll number to search: ";
    // Asks the user to enter the roll number.

    std::cin >> targetRollNumber;
    // Reads the roll number entered by the user.

    std::string line;
    // Stores one complete line from the file.

    bool found = false;
    // Keeps track of whether the required student is found.

    while (std::getline(inputFile, line)) {
        // Reads the file one line at a time.

        std::stringstream record(line);
        // Converts the current line into a stringstream
        // so that its fields can be separated.

        std::string rollText;
        // Stores the roll number as text.

        std::string name;
        // Stores the student's name.

        std::string marksText;
        // Stores the marks as text.

        std::getline(record, rollText, '|');
        // Reads the roll number up to the | delimiter.

        std::getline(record, name, '|');
        // Reads the student's name up to the | delimiter.

        std::getline(record, marksText, '|');
        // Reads the marks up to the | delimiter.

        int rollNumber = std::stoi(rollText);
        // Converts the roll number from string to integer.

        double marks = std::stod(marksText);
        // Converts the marks from string to double.

        if (rollNumber == targetRollNumber) {
            // Checks whether the current roll number
            // matches the roll number entered by the user.

            std::cout << "Roll Number: " << rollNumber << '\n';
            // Displays the student's roll number.

            std::cout << "Name: " << name << '\n';
            // Displays the student's name.

            std::cout << "Marks: " << marks << '\n';
            // Displays the student's marks.

            found = true;
            // Marks that the student was found.

            break;
            // Stops searching because the required record was found.
        }
    }

    if (!found) {
        // Checks whether no matching student was found.

        std::cout << "Student record not found.\n";
        // Displays a message when the record does not exist.
    }

    return 0;
    // Ends the program successfully.
}