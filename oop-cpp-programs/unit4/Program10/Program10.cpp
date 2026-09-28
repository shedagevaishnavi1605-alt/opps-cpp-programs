#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.
#include <string>       // Includes string support.

int main() {            // Main function where program execution starts.

    std::fstream file(
        "navigation.txt",
        std::ios::in | std::ios::out | std::ios::trunc
    );
    // Opens navigation.txt for both reading and writing.
    // std::ios::trunc clears the old contents of the file.

    if (!file) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open navigation.txt\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Stops the program because an error occurred.
    }

    file << "ABCDE";
    // Writes ABCDE into the file.

    std::cout << "Output position after writing: "
              << file.tellp() << '\n';
    // tellp() gives the current position of the output/write pointer.
    // After writing 5 characters, the position is 5.

    file.flush();
    // Ensures that the written data is sent to the file.

    file.seekg(0, std::ios::beg);
    // Moves the input/read pointer to the beginning of the file.

    char firstCharacter;
    // Creates a character variable to store the first character.

    file.get(firstCharacter);
    // Reads the first character from the file.

    std::cout << "First character: "
              << firstCharacter << '\n';
    // Displays the first character, which is A.

    std::cout << "Input position: "
              << file.tellg() << '\n';
    // tellg() gives the current position of the input/read pointer.
    // After reading A, the position is 1.

    file.seekg(2, std::ios::beg);
    // Moves the input pointer 2 positions from the beginning.
    // Position 0 = A, position 1 = B, position 2 = C.

    char thirdCharacter;
    // Creates a character variable for the third character.

    file.get(thirdCharacter);
    // Reads the character at position 2.

    std::cout << "Character at position 2: "
              << thirdCharacter << '\n';
    // Displays C.

    file.seekp(5, std::ios::beg);
    // Moves the output/write pointer to position 5 from the beginning.

    file << 'F';
    // Writes F at position 5.
    // The file now contains ABCDEF.

    file.close();
    // Closes the file.

    std::cout << "File pointer navigation completed.\n";
    // Displays a success message.

    return 0;
    // Ends the program successfully.
}