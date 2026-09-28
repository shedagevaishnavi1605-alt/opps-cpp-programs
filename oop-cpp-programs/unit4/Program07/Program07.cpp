#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.
#include <limits>       // Includes numeric_limits for clearing input.
#include <string>       // Includes string support.

int main() {            // Main function where program execution starts.

    std::ofstream outputFile("students.txt", std::ios::app);
    // Opens students.txt in append mode.
    // New student records are added at the end of the file.

    if (!outputFile) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open students.txt\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Stops the program because an error occurred.
    }

    int rollNumber;
    // Creates an integer variable to store the student's roll number.

    std::string name;
    // Creates a string variable to store the student's name.

    double marks;
    // Creates a variable to store the student's marks.

    std::cout << "Enter roll number: ";
    // Asks the user to enter the roll number.

    std::cin >> rollNumber;
    // Reads the roll number from the user.

    std::cout << "Enter student name: ";
    // Asks the user to enter the student's name.

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Clears the remaining newline from the input buffer.
    // This allows getline() to correctly read the complete name.

    std::getline(std::cin, name);
    // Reads the complete student name, including spaces.

    std::cout << "Enter marks: ";
    // Asks the user to enter the marks.

    std::cin >> marks;
    // Reads the marks from the user.

    outputFile << rollNumber << '|' << name << '|' << marks << '\n';
    // Stores the student record in the file.
    // | is used as a delimiter between the fields.

    std::cout << "Student record saved successfully.\n";
    // Displays a success message.

    return 0;
    // Ends the program successfully.
}