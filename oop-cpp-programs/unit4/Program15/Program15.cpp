#include <cstdio>       // Includes remove() and rename().
#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.
#include <limits>       // Includes numeric_limits.
#include <sstream>      // Includes stringstream for parsing records.
#include <string>       // Includes string support.


void addStudent() {
    // Function to add a new student record.

    std::ofstream outputFile(
        "student_records.txt",
        std::ios::app
    );
    // Opens student_records.txt in append mode.
    // New records are added at the end of the file.

    if (!outputFile) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open student_records.txt\n";
        // Displays an error message.

        return;
        // Returns to the main menu.
    }

    int rollNumber;
    // Stores the student's roll number.

    std::string name;
    // Stores the student's name.

    double marks;
    // Stores the student's marks.

    std::cout << "Enter roll number: ";
    // Asks the user for the roll number.

    std::cin >> rollNumber;
    // Reads the roll number.

    std::cout << "Enter student name: ";
    // Asks the user for the student's name.

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );
    // Clears the remaining newline from the input buffer.

    std::getline(std::cin, name);
    // Reads the complete student name.

    std::cout << "Enter marks: ";
    // Asks the user for marks.

    std::cin >> marks;
    // Reads the marks.

    outputFile << rollNumber << '|'
               << name << '|'
               << marks << '\n';
    // Saves the student record using | as a delimiter.

    std::cout << "Student added successfully.\n";
    // Displays a success message.
}


void displayStudents() {
    // Function to display all student records.

    std::ifstream inputFile("student_records.txt");
    // Opens the student records file for reading.

    if (!inputFile) {
        // Checks whether the file exists and opened successfully.

        std::cout << "No student records found.\n";
        // Displays a message if there are no records.

        return;
        // Returns to the main menu.
    }

    std::string line;
    // Stores one complete record line.

    std::cout << "\nStudent Records\n";
    // Displays the heading.

    std::cout << "-------------------------\n";
    // Displays a separator.

    while (std::getline(inputFile, line)) {
        // Reads each student record line by line.

        std::stringstream record(line);
        // Converts the line into a stringstream.

        std::string rollText;
        // Stores the roll number as text.

        std::string name;
        // Stores the student's name.

        std::string marksText;
        // Stores the marks as text.

        std::getline(record, rollText, '|');
        // Reads the roll number up to |.

        std::getline(record, name, '|');
        // Reads the name up to |.

        std::getline(record, marksText, '|');
        // Reads the marks up to |.

        std::cout << "Roll Number: " << rollText << '\n';
        // Displays the roll number.

        std::cout << "Name: " << name << '\n';
        // Displays the student's name.

        std::cout << "Marks: " << marksText << '\n';
        // Displays the student's marks.

        std::cout << "-------------------------\n";
        // Displays a separator between records.
    }
}


void searchStudent() {
    // Function to search for a student using roll number.

    std::ifstream inputFile("student_records.txt");
    // Opens the student records file.

    if (!inputFile) {
        // Checks whether the file exists.

        std::cout << "No student records found.\n";
        // Displays a message if the file does not exist.

        return;
        // Returns to the main menu.
    }

    int targetRollNumber;
    // Stores the roll number to search.

    std::cout << "Enter roll number to search: ";
    // Asks the user for the roll number.

    std::cin >> targetRollNumber;
    // Reads the roll number.

    std::string line;
    // Stores one record line.

    bool found = false;
    // Keeps track of whether the student was found.

    while (std::getline(inputFile, line)) {
        // Reads the file one record at a time.

        std::stringstream record(line);
        // Converts the record into a stringstream.

        std::string rollText;
        // Stores roll number as text.

        std::string name;
        // Stores the student's name.

        std::string marksText;
        // Stores marks as text.

        std::getline(record, rollText, '|');
        // Reads roll number.

        std::getline(record, name, '|');
        // Reads student name.

        std::getline(record, marksText, '|');
        // Reads marks.

        int rollNumber = std::stoi(rollText);
        // Converts roll number from string to integer.

        if (rollNumber == targetRollNumber) {
            // Checks whether the roll number matches.

            std::cout << "Roll Number: " << rollNumber << '\n';
            // Displays the roll number.

            std::cout << "Name: " << name << '\n';
            // Displays the student's name.

            std::cout << "Marks: " << marksText << '\n';
            // Displays the student's marks.

            found = true;
            // Marks that the student was found.

            break;
            // Stops searching.
        }
    }

    if (!found) {
        // Checks whether no matching record was found.

        std::cout << "Student record not found.\n";
        // Displays the not-found message.
    }
}


void updateMarks() {
    // Function to update the marks of a student.

    std::ifstream inputFile("student_records.txt");
    // Opens the original file for reading.

    std::ofstream tempFile("student_records_temp.txt");
    // Creates a temporary file for updated records.

    if (!inputFile || !tempFile) {
        // Checks whether both files opened successfully.

        std::cerr << "Error: Could not open required files.\n";
        // Displays an error message.

        return;
        // Returns to the main menu.
    }

    int targetRollNumber;
    // Stores the roll number to update.

    double newMarks;
    // Stores the new marks.

    std::cout << "Enter roll number to update: ";
    // Asks for the roll number.

    std::cin >> targetRollNumber;
    // Reads the roll number.

    std::cout << "Enter new marks: ";
    // Asks for the new marks.

    std::cin >> newMarks;
    // Reads the new marks.

    std::string line;
    // Stores one record line.

    bool found = false;
    // Keeps track of whether the student was found.

    while (std::getline(inputFile, line)) {
        // Reads the original file one line at a time.

        std::stringstream record(line);
        // Converts the line into a stringstream.

        std::string rollText;
        // Stores roll number as text.

        std::string name;
        // Stores student name.

        std::string marksText;
        // Stores marks as text.

        std::getline(record, rollText, '|');
        // Reads roll number.

        std::getline(record, name, '|');
        // Reads student name.

        std::getline(record, marksText, '|');
        // Reads marks.

        int rollNumber = std::stoi(rollText);
        // Converts roll number from string to integer.

        if (rollNumber == targetRollNumber) {
            // Checks whether this is the student to update.

            tempFile << rollNumber << '|'
                     << name << '|'
                     << newMarks << '\n';
            // Writes the updated record into the temporary file.

            found = true;
            // Marks that the student was found.
        }
        else {
            // Executes for records that should not be changed.

            tempFile << line << '\n';
            // Copies the original record unchanged.
        }
    }

    inputFile.close();
    // Closes the original file.

    tempFile.close();
    // Closes the temporary file.

    if (!found) {
        // Checks whether the student was not found.

        std::remove("student_records_temp.txt");
        // Deletes the temporary file.

        std::cout << "Student record not found. No changes made.\n";
        // Displays a message.

        return;
        // Returns to the main menu.
    }

    std::remove("student_records.txt");
    // Deletes the original student records file.

    if (std::rename(
            "student_records_temp.txt",
            "student_records.txt") != 0) {
        // Renames the temporary file to the original filename.
        // Checks whether the rename operation failed.

        std::cerr << "Error: Could not rename temporary file.\n";
        // Displays an error message.

        return;
        // Returns to the main menu.
    }

    std::cout << "Student marks updated successfully.\n";
    // Displays a success message.
}


int main() {
    // Main function where program execution starts.

    int choice;
    // Stores the user's menu choice.

    do {
        // Starts a loop that continues until the user chooses 0.

        std::cout << "\nStudent Record Manager\n";
        // Displays the program heading.

        std::cout << "1. Add Student\n";
        // Displays option 1.

        std::cout << "2. Display Students\n";
        // Displays option 2.

        std::cout << "3. Search Student\n";
        // Displays option 3.

        std::cout << "4. Update Marks\n";
        // Displays option 4.

        std::cout << "0. Exit\n";
        // Displays option 0.

        std::cout << "Enter your choice: ";
        // Asks the user to select an option.

        std::cin >> choice;
        // Reads the user's choice.

        switch (choice) {
            // Selects an operation based on the user's choice.

            case 1:
                // Option 1: Add a student.

                addStudent();
                // Calls the addStudent() function.

                break;
                // Exits this case.

            case 2:
                // Option 2: Display students.

                displayStudents();
                // Calls the displayStudents() function.

                break;
                // Exits this case.

            case 3:
                // Option 3: Search for a student.

                searchStudent();
                // Calls the searchStudent() function.

                break;
                // Exits this case.

            case 4:
                // Option 4: Update marks.

                updateMarks();
                // Calls the updateMarks() function.

                break;
                // Exits this case.

            case 0:
                // Option 0: Exit the program.

                std::cout << "Exiting...\n";
                // Displays an exit message.

                break;
                // Exits the switch statement.

            default:
                // Executes when the user enters an invalid choice.

                std::cout << "Invalid choice.\n";
                // Displays an invalid-choice message.
        }

    } while (choice != 0);
    // Repeats the menu until the user chooses 0.

    return 0;
    // Ends the program successfully.
}