#include <cctype>       // Includes functions like isspace().
#include <fstream>      // Includes the file-stream library.
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

    std::size_t lineCount = 0;
    // Creates a variable to store the number of lines.

    std::size_t wordCount = 0;
    // Creates a variable to store the number of words.

    std::size_t characterCount = 0;
    // Creates a variable to store the number of characters.

    bool insideWord = false;
    // Keeps track of whether the program is currently inside a word.

    char ch;
    // Creates a character variable to read one character at a time.

    while (inputFile.get(ch)) {
        // Reads one character from the file at a time.
        // The loop continues while characters are successfully read.

        ++characterCount;
        // Increases the character count by 1.

        if (ch == '\n') {
            // Checks whether the current character is a newline.

            ++lineCount;
            // Increases the line count by 1.
        }

        if (std::isspace(static_cast<unsigned char>(ch))) {
            // Checks whether the character is a space, tab, or newline.

            insideWord = false;
            // Indicates that we are outside a word.
        }
        else if (!insideWord) {
            // If the character is not whitespace and we were outside a word,
            // a new word has started.

            ++wordCount;
            // Increases the word count by 1.

            insideWord = true;
            // Indicates that we are now inside a word.
        }
    }

    if (characterCount > 0) {
        // Checks whether the file contains at least one character.

        inputFile.clear();
        // Clears the end-of-file state so we can perform another file operation.

        inputFile.seekg(-1, std::ios::end);
        // Moves the file reading position to the last character of the file.

        char lastCharacter;
        // Creates a variable to store the last character.

        inputFile.get(lastCharacter);
        // Reads the last character of the file.

        if (lastCharacter != '\n') {
            // Checks whether the last character is not a newline.

            ++lineCount;
            // Counts the final line if it does not end with a newline.
        }
    }

    std::cout << "Lines: " << lineCount << '\n';
    // Displays the total number of lines.

    std::cout << "Words: " << wordCount << '\n';
    // Displays the total number of words.

    std::cout << "Characters: " << characterCount << '\n';
    // Displays the total number of characters.

    return 0;
    // Ends the program successfully.
}