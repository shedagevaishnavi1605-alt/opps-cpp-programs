#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.
#include <string>       // Includes string support.

int main() {
    // Main function where program execution starts.

    std::ifstream inputFile("missing_file.txt");
    // Tries to open missing_file.txt for reading.

    if (!inputFile.is_open()) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open missing_file.txt\n";
        // Displays an error message if the file cannot be opened.

        std::cerr << "Hint: Check the file name and path.\n";
        // Gives the user a hint to check the file name and location.

        return 1;
        // Stops the program because the file could not be opened.
    }

    std::string line;
    // Creates a string variable to store each line.

    while (std::getline(inputFile, line)) {
        // Reads the file one line at a time.

        std::cout << line << '\n';
        // Displays the current line on the screen.
    }

    if (inputFile.eof()) {
        // Checks whether the end of the file was reached normally.

        std::cout << "File read completed normally.\n";
        // Displays a message when the file was read successfully.
    }
    else if (inputFile.bad()) {
        // Checks whether a serious input/output error occurred.

        std::cerr << "A serious file error occurred.\n";
        // Displays an error message.
    }
    else if (inputFile.fail()) {
        // Checks whether a logical/read operation failed.

        std::cerr << "A logical file read error occurred.\n";
        // Displays a message for the read error.
    }

    return 0;
    // Ends the program successfully.
}