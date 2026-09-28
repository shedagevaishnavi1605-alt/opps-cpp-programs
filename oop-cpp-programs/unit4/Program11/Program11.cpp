#include <cstring>      // Includes functions like strncpy().
#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.

struct StudentRecord {
    // Defines a structure to store one student's record.

    int rollNumber;
    // Stores the student's roll number.

    char name[30];
    // Stores the student's name as a character array.

    float marks;
    // Stores the student's marks.
};

int main() {
    // Main function where program execution starts.

    StudentRecord student{};
    // Creates a StudentRecord object.
    // {} initializes its members to default values.

    student.rollNumber = 101;
    // Assigns 101 as the student's roll number.

    std::strncpy(student.name, "Amit Patil", sizeof(student.name) - 1);
    // Copies "Amit Patil" into the name character array.
    // sizeof(student.name) - 1 keeps space for the null character.

    student.marks = 85.5F;
    // Assigns 85.5 as the student's marks.

    std::ofstream outputFile(
        "students.dat",
        std::ios::binary
    );
    // Opens students.dat in binary writing mode.

    if (!outputFile) {
        // Checks whether the binary file was opened successfully.

        std::cerr << "Error: Could not create students.dat\n";
        // Displays an error message if the file cannot be created.

        return 1;
        // Stops the program because an error occurred.
    }

    outputFile.write(
        reinterpret_cast<const char*>(&student),
        sizeof(student)
    );
    // Writes the complete StudentRecord object
    // as raw binary data into the file.

    outputFile.close();
    // Closes the output file.

    StudentRecord readStudent{};
    // Creates another StudentRecord object
    // to store the record read from the file.

    std::ifstream inputFile(
        "students.dat",
        std::ios::binary
    );
    // Opens students.dat in binary reading mode.

    if (!inputFile) {
        // Checks whether the binary file was opened successfully.

        std::cerr << "Error: Could not open students.dat\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Stops the program because an error occurred.
    }

    inputFile.read(
        reinterpret_cast<char*>(&readStudent),
        sizeof(readStudent)
    );
    // Reads the binary data from the file
    // and stores it inside readStudent.

    if (!inputFile) {
        // Checks whether the reading operation was successful.

        std::cerr << "Error: Could not read the student record\n";
        // Displays an error message if reading fails.

        return 1;
        // Stops the program because an error occurred.
    }

    std::cout << "Roll Number: "
              << readStudent.rollNumber << '\n';
    // Displays the student's roll number.

    std::cout << "Name: "
              << readStudent.name << '\n';
    // Displays the student's name.

    std::cout << "Marks: "
              << readStudent.marks << '\n';
    // Displays the student's marks.

    return 0;
    // Ends the program successfully.
}