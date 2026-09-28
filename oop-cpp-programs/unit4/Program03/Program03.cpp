#include <fstream>      // Includes the file-stream library for file handling.
#include <iostream>     // Includes the input/output library.

int main() {            // Main function where program execution starts.

    std::ofstream outputFile("message.txt", std::ios::app);
    // Opens "message.txt" in append mode.
    // std::ios::app adds new data at the end of the existing file.
    // Existing data is not deleted.

    if (!outputFile) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open message.txt for appending\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Stops the program and indicates an error.
    }

    outputFile << "This line was added using append mode.\n";
    // Adds this new line at the end of the existing file.

    outputFile.close();
    // Closes the file after writing is completed.

    std::cout << "New line appended successfully.\n";
    // Displays a success message on the console.

    return 0;
    // Ends the program successfully.
}