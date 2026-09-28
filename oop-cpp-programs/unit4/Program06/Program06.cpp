#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.
#include <string>       // Includes string support.

int main() {            // Main function where program execution starts.

    std::ifstream inputFile("message.txt");
    // Opens "message.txt" for reading.

    if (!inputFile) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open message.txt\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Stops the program because an error occurred.
    }

    std::string searchWord;
    // Creates a string variable to store the word entered by the user.

    std::cout << "Enter word to search: ";
    // Asks the user to enter the word to search.

    std::cin >> searchWord;
    // Reads the word entered by the user.

    std::string word;
    // Creates a string variable to store each word read from the file.

    int count = 0;
    // Creates a variable to count how many times the word occurs.

    while (inputFile >> word) {
        // Reads one word at a time from the file.
        // The loop continues until the end of the file.

        if (word == searchWord) {
            // Checks whether the current file word matches
            // the word entered by the user.

            ++count;
            // Increases the count by 1 when a match is found.
        }
    }

    std::cout << "The word '" << searchWord
              << "' occurred " << count << " time(s).\n";
    // Displays the searched word and the number of times it occurred.

    return 0;
    // Ends the program successfully.
}