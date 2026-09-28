#include <fstream>      // Includes the file-stream library for file handling.
#include <iostream>     // Includes the input/output library for cout and cerr.

int main() {            // Main function where program execution starts.

    std::ofstream outputFile("message.txt");
    // Creates/opens a file named "message.txt" for writing.
    // ofstream is used to write data into a file.

    if (!outputFile) {
        // Checks whether the file was opened/created successfully.

        std::cerr << "Error: Could not create message.txt\n";
        // Displays an error message if the file could not be created.

        return 1;
        // Stops the program and returns 1 to indicate an error.
    }

    outputFile << "Welcome to C++ File Handling\n";
    // Writes the first line of text into message.txt.

    outputFile << "This is the first line written to a file.\n";
    // Writes the second line into the file.

    outputFile << "Files store data permanently.\n";
    // Writes the third line into the file.

    outputFile.close();
    // Closes the file after writing is completed.

    std::cout << "Data written successfully to message.txt\n";
    // Displays a success message on the console.

    return 0;
    // Ends the program successfully.
}