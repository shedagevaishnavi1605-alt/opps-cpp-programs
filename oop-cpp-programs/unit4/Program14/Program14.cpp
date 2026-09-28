#include <cctype>      // Includes character-checking functions.
#include <fstream>     // Includes file handling functions.
#include <iostream>    // Includes input/output functions.
#include <string>      // Includes string support.

bool isVowel(char ch) {
    // Function to check whether a character is a vowel.

    ch = static_cast<char>(std::tolower(
        static_cast<unsigned char>(ch)
    ));
    // Converts the character into lowercase.

    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
    // Returns true if the character is a vowel.
}

int main() {
    // Main function where program execution starts.

    std::string fileName;
    // Creates a string variable to store the file name.

    std::cout << "Enter file name: ";
    // Asks the user to enter the file name.

    std::getline(std::cin, fileName);
    // Reads the complete file name entered by the user.

    std::ifstream file(fileName);
    // Opens the entered file for reading.

    if (!file) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open the file.\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Stops the program because an error occurred.
    }

    std::size_t lines = 0;
    // Stores the number of lines.

    std::size_t words = 0;
    // Stores the number of words.

    std::size_t characters = 0;
    // Stores the number of characters.

    std::size_t vowels = 0;
    // Stores the number of vowels.

    std::size_t digits = 0;
    // Stores the number of digits.

    std::size_t spaces = 0;
    // Stores the number of spaces.

    bool insideWord = false;
    // Keeps track of whether the program is currently inside a word.

    char ch;
    // Stores one character read from the file.

    while (file.get(ch)) {
        // Reads the file one character at a time.

        ++characters;
        // Increases the character count by 1.

        if (ch == '\n') {
            // Checks whether the character is a newline.

            ++lines;
            // Increases the line count by 1.
        }

        if (std::isspace(static_cast<unsigned char>(ch))) {
            // Checks whether the character is whitespace.

            if (ch == ' ') {
                // Checks specifically for a normal space.

                ++spaces;
                // Increases the space count by 1.
            }

            insideWord = false;
            // Indicates that we are outside a word.
        }
        else if (!insideWord) {
            // If the character is not whitespace and we were
            // outside a word, a new word has started.

            ++words;
            // Increases the word count by 1.

            insideWord = true;
            // Indicates that we are now inside a word.
        }

        if (std::isalpha(static_cast<unsigned char>(ch))
            && isVowel(ch)) {
            // Checks whether the character is an alphabet
            // and also a vowel.

            ++vowels;
            // Increases the vowel count by 1.
        }

        if (std::isdigit(static_cast<unsigned char>(ch))) {
            // Checks whether the character is a digit.

            ++digits;
            // Increases the digit count by 1.
        }
    }

    if (characters > 0) {
        // Checks whether the file contains at least one character.

        file.clear();
        // Clears the end-of-file state.

        file.seekg(-1, std::ios::end);
        // Moves the reading pointer to the last character.

        char lastCharacter;
        // Creates a variable to store the last character.

        file.get(lastCharacter);
        // Reads the last character.

        if (lastCharacter != '\n') {
            // Checks whether the file does not end with a newline.

            ++lines;
            // Counts the final line.
        }
    }

    std::cout << "\nFile Statistics\n";
    // Displays the heading.

    std::cout << "----------------\n";
    // Displays a separator line.

    std::cout << "Lines: " << lines << '\n';
    // Displays the total number of lines.

    std::cout << "Words: " << words << '\n';
    // Displays the total number of words.

    std::cout << "Characters: " << characters << '\n';
    // Displays the total number of characters.

    std::cout << "Vowels: " << vowels << '\n';
    // Displays the total number of vowels.

    std::cout << "Digits: " << digits << '\n';
    // Displays the total number of digits.

    std::cout << "Spaces: " << spaces << '\n';
    // Displays the total number of spaces.

    return 0;
    // Ends the program successfully.
}