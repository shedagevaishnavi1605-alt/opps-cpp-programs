#include <fstream>      // Includes the file-stream library for file handling.
#include <iostream>     // Includes the input/output library.
#include <string>       // Includes the string library for using string variables.

int main() {            // Main function where program execution starts.

    std::ifstream inputFile("message.txt");
    // Opens the "message.txt" file for reading.
    // ifstream is used to read data from a file.

    if (!inputFile) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open message.txt\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Stops the program and indicates that an error occurred.
    }

    std::string line;
    // Creates a string variable named 'line' to store each line read from the file.

    std::cout << "File Content:\n";
    // Displays the heading "File Content:" on the screen.

    while (std::getline(inputFile, line)) {
        // Reads one complete line from the file.
        // The loop continues as long as a line is successfully read.

        std::cout << line << '\n';
        // Displays the current line on the console.
    }

    inputFile.close();
    // Closes the file after reading is completed.

    return 0;
    // Ends the program successfully.
}