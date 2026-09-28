#include <fstream>      // Includes the file-stream library for reading and writing files.
#include <iostream>     // Includes the input/output library.
#include <string>       // Includes the string library for using string variables.

int main() {            // Main function where program execution starts.

    std::ifstream sourceFile("message.txt");
    // Opens "message.txt" for reading.
    // This is the source file from which data will be copied.

    std::ofstream destinationFile("message_copy.txt");
    // Creates/opens "message_copy.txt" for writing.
    // The copied data will be stored in this file.

    if (!sourceFile) {
        // Checks whether the source file was opened successfully.

        std::cerr << "Error: Could not open source file.\n";
        // Displays an error message if the source file cannot be opened.

        return 1;
        // Stops the program because the source file is unavailable.
    }

    if (!destinationFile) {
        // Checks whether the destination file was created/opened successfully.

        std::cerr << "Error: Could not create destination file.\n";
        // Displays an error message if the destination file cannot be created.

        return 1;
        // Stops the program because the destination file is unavailable.
    }

    std::string line;
    // Creates a string variable to store each line of the source file.

    while (std::getline(sourceFile, line)) {
        // Reads one complete line from the source file.
        // The loop continues until all lines are read.

        destinationFile << line << '\n';
        // Writes the current line into the destination file.
    }

    std::cout << "File copied successfully to message_copy.txt\n";
    // Displays a success message on the console.

    return 0;
    // Ends the program successfully.
}