#include <cstring>      // Includes functions like strncpy().
#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.

struct StudentRecord {
    // Defines a structure to store one student's record.

    int rollNumber;
    // Stores the student's roll number.

    char name[30];
    // Stores the student's name.

    float marks;
    // Stores the student's marks.
};

void addRecord(std::ofstream& file, int rollNumber,
               const char* name, float marks) {
    // Function used to add one student record to the binary file.

    StudentRecord student{};
    // Creates a StudentRecord object and initializes it.

    student.rollNumber = rollNumber;
    // Stores the roll number in the record.

    std::strncpy(student.name, name, sizeof(student.name) - 1);
    // Copies the student's name into the character array.

    student.marks = marks;
    // Stores the student's marks.

    file.write(
        reinterpret_cast<const char*>(&student),
        sizeof(student)
    );
    // Writes the complete student record into the binary file.
}

int main() {
    // Main function where program execution starts.

    std::ofstream outputFile(
        "records.dat",
        std::ios::binary | std::ios::trunc
    );
    // Opens records.dat in binary mode.
    // std::ios::trunc removes any old contents.

    if (!outputFile) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not create records.dat\n";
        // Displays an error message.

        return 1;
        // Stops the program because an error occurred.
    }

    addRecord(outputFile, 101, "Amit", 85.5F);
    // Adds the first student record.

    addRecord(outputFile, 102, "Neha", 91.0F);
    // Adds the second student record.

    addRecord(outputFile, 103, "Ravi", 78.0F);
    // Adds the third student record.

    outputFile.close();
    // Closes the output file.

    std::ifstream inputFile(
        "records.dat",
        std::ios::binary
    );
    // Opens records.dat in binary reading mode.

    if (!inputFile) {
        // Checks whether the file was opened successfully.

        std::cerr << "Error: Could not open records.dat\n";
        // Displays an error message.

        return 1;
        // Stops the program because an error occurred.
    }

    int recordNumber;
    // Stores the record number selected by the user.

    std::cout << "Enter record number (1 to 3): ";
    // Asks the user which record they want to read.

    std::cin >> recordNumber;
    // Reads the record number.

    if (recordNumber < 1 || recordNumber > 3) {
        // Checks whether the entered record number is outside
        // the valid range of 1 to 3.

        std::cerr << "Error: Invalid record number\n";
        // Displays an error message.

        return 1;
        // Stops the program.
    }

    std::streamoff offset =
        static_cast<std::streamoff>(recordNumber - 1)
        * static_cast<std::streamoff>(sizeof(StudentRecord));
    // Calculates the byte position of the selected record.
    // Record 1 starts at 0.
    // Record 2 starts after one StudentRecord.
    // Record 3 starts after two StudentRecords.

    inputFile.seekg(offset, std::ios::beg);
    // Moves the file's reading pointer directly
    // to the selected record.

    StudentRecord selectedStudent{};
    // Creates an object to store the selected student's record.

    inputFile.read(
        reinterpret_cast<char*>(&selectedStudent),
        sizeof(selectedStudent)
    );
    // Reads the selected record from the binary file.

    if (!inputFile) {
        // Checks whether the record was read successfully.

        std::cerr << "Error: Could not read the selected record\n";
        // Displays an error message if reading fails.

        return 1;
        // Stops the program.
    }

    std::cout << "Roll Number: "
              << selectedStudent.rollNumber << '\n';
    // Displays the selected student's roll number.

    std::cout << "Name: "
              << selectedStudent.name << '\n';
    // Displays the selected student's name.

    std::cout << "Marks: "
              << selectedStudent.marks << '\n';
    // Displays the selected student's marks.

    return 0;
    // Ends the program successfully.
}