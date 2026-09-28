#include <cstdio>       // Includes remove() and rename() functions.
#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.
#include <sstream>      // Includes stringstream for splitting records.
#include <string>       // Includes string support.

int main() {            // Main function where program execution starts.

    std::ifstream inputFile("students.txt");
    // Opens the original students.txt file for reading.

    std::ofstream tempFile("students_temp.txt");
    // Creates a temporary file to store the updated records.

    if (!inputFile || !tempFile) {
        // Checks whether both files were opened successfully.

        std::cerr << "Error: Could not open required files.\n";
        // Displays an error message if either file could not be opened.

        return 1;
        // Stops the program because an error occurred.
    }

    int targetRollNumber;
    // Stores the roll number of the student whose marks need to be updated.

    double updatedMarks;
    // Stores the new marks.

    std::cout << "Enter roll number to update: ";
    // Asks the user for the roll number.

    std::cin >> targetRollNumber;
    // Reads the roll number entered by the user.

    std::cout << "Enter new marks: ";
    // Asks the user for the new marks.

    std::cin >> updatedMarks;
    // Reads the new marks.

    std::string line;
    // Stores one complete line from the file.

    bool found = false;
    // Keeps track of whether the required student was found.

    while (std::getline(inputFile, line)) {
        // Reads the original file one line at a time.

        std::stringstream record(line);
        // Converts the current line into a stringstream
        // for separating the record fields.

        std::string rollText;
        // Stores the roll number as text.

        std::string name;
        // Stores the student's name.

        std::string marksText;
        // Stores the marks as text.

        std::getline(record, rollText, '|');
        // Reads the roll number up to the | delimiter.

        std::getline(record, name, '|');
        // Reads the student's name up to the | delimiter.

        std::getline(record, marksText, '|');
        // Reads the marks up to the | delimiter.

        int rollNumber = std::stoi(rollText);
        // Converts the roll number from string to integer.

        if (rollNumber == targetRollNumber) {
            // Checks whether this is the student we want to update.

            tempFile << rollNumber << '|' << name << '|'
                     << updatedMarks << '\n';
            // Writes the updated student record into the temporary file.

            found = true;
            // Indicates that the student was found and updated.
        }
        else {
            // Executes when the current student is not the target student.

            tempFile << line << '\n';
            // Copies the original record into the temporary file unchanged.
        }
    }

    inputFile.close();
    // Closes the original students.txt file.

    tempFile.close();
    // Closes the temporary file.

    if (!found) {
        // Checks whether the requested student was not found.

        std::remove("students_temp.txt");
        // Deletes the temporary file because no update was made.

        std::cout << "Student record not found. No changes made.\n";
        // Displays a message saying that no record was updated.

        return 0;
        // Ends the program.
    }

    if (std::remove("students.txt") != 0) {
        // Deletes the original students.txt file.
        // Checks whether the deletion was successful.

        std::cerr << "Error: Could not remove original file.\n";
        // Displays an error if the original file cannot be removed.

        return 1;
        // Stops the program because an error occurred.
    }

    if (std::rename("students_temp.txt", "students.txt") != 0) {
        // Renames the temporary file to students.txt.

        std::cerr << "Error: Could not rename temporary file.\n";
        // Displays an error if renaming fails.

        return 1;
        // Stops the program because an error occurred.
    }

    std::cout << "Student record updated successfully.\n";
    // Displays a success message.

    return 0;
    // Ends the program successfully.
}