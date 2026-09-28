#include <fstream>      // Includes file handling functions.
#include <iostream>     // Includes input/output functions.
#include <limits>       // Includes numeric_limits.
#include <sstream>      // Includes stringstream for parsing records.
#include <string>       // Includes string support.

class Book {
    // Defines a Book class to represent a library book.

private:
    int bookId;
    // Stores the unique ID of the book.

    std::string title;
    // Stores the title of the book.

    std::string author;
    // Stores the author's name.

    bool issued;
    // Stores whether the book is issued or not.

public:

    Book(int id, std::string bookTitle,
         std::string bookAuthor, bool isIssued = false)
        : bookId(id),
          title(std::move(bookTitle)),
          author(std::move(bookAuthor)),
          issued(isIssued) {
        // Constructor initializes all Book data members.
    }

    int getBookId() const {
        // Function to return the book ID.

        return bookId;
        // Returns the book ID.
    }

    std::string toFileRecord() const {
        // Converts the Book object into a file record.

        return std::to_string(bookId) + "|" +
               title + "|" +
               author + "|" +
               (issued ? "1" : "0");
        // Creates a delimiter-separated record.
        // 1 means issued and 0 means available.
    }

    void display() const {
        // Function to display book information.

        std::cout << "Book ID: " << bookId << '\n';
        // Displays the book ID.

        std::cout << "Title: " << title << '\n';
        // Displays the book title.

        std::cout << "Author: " << author << '\n';
        // Displays the author's name.

        std::cout << "Status: "
                  << (issued ? "Issued" : "Available")
                  << '\n';
        // Displays whether the book is issued or available.
    }
};


void addBook() {
    // Function to add a new book.

    int id;
    // Stores the book ID.

    std::string title;
    // Stores the book title.

    std::string author;
    // Stores the author's name.

    std::cout << "Enter book ID: ";
    // Asks the user for the book ID.

    std::cin >> id;
    // Reads the book ID.

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );
    // Clears the remaining newline from the input buffer.

    std::cout << "Enter book title: ";
    // Asks the user for the book title.

    std::getline(std::cin, title);
    // Reads the complete book title.

    std::cout << "Enter author name: ";
    // Asks the user for the author's name.

    std::getline(std::cin, author);
    // Reads the complete author name.

    Book book(id, title, author);
    // Creates a Book object using the entered details.

    std::ofstream outputFile(
        "library.txt",
        std::ios::app
    );
    // Opens library.txt in append mode.

    if (!outputFile) {
        // Checks whether the file opened successfully.

        std::cerr << "Error: Could not open library.txt\n";
        // Displays an error message.

        return;
        // Returns to the main menu.
    }

    outputFile << book.toFileRecord() << '\n';
    // Converts the Book object into a record
    // and stores it in the file.

    std::cout << "Book added successfully.\n";
    // Displays a success message.
}


void displayBooks() {
    // Function to display all books.

    std::ifstream inputFile("library.txt");
    // Opens library.txt for reading.

    if (!inputFile) {
        // Checks whether the file exists.

        std::cout << "No library records found.\n";
        // Displays a message if there are no records.

        return;
        // Returns to the main menu.
    }

    std::string line;
    // Stores one record line from the file.

    while (std::getline(inputFile, line)) {
        // Reads the file one record at a time.

        std::stringstream record(line);
        // Converts the line into a stringstream.

        std::string idText;
        // Stores the book ID as text.

        std::string title;
        // Stores the book title.

        std::string author;
        // Stores the author's name.

        std::string issuedText;
        // Stores the issued status as text.

        std::getline(record, idText, '|');
        // Reads the book ID up to the | delimiter.

        std::getline(record, title, '|');
        // Reads the title up to the | delimiter.

        std::getline(record, author, '|');
        // Reads the author up to the | delimiter.

        std::getline(record, issuedText, '|');
        // Reads the issued status up to the | delimiter.

        Book book(
            std::stoi(idText),
            title,
            author,
            issuedText == "1"
        );
        // Converts the ID to an integer and creates
        // a Book object using the file data.

        book.display();
        // Displays the book information.

        std::cout << "-------------------------\n";
        // Displays a separator between books.
    }
}


int main() {
    // Main function where program execution starts.

    int choice;
    // Stores the user's menu choice.

    do {
        // Starts a loop that continues until the user chooses 0.

        std::cout << "\nLibrary Record Manager\n";
        // Displays the program heading.

        std::cout << "1. Add Book\n";
        // Displays option 1.

        std::cout << "2. Display Books\n";
        // Displays option 2.

        std::cout << "0. Exit\n";
        // Displays option 0.

        std::cout << "Enter your choice: ";
        // Asks the user to enter a choice.

        std::cin >> choice;
        // Reads the user's choice.

        switch (choice) {
            // Selects an operation based on the user's choice.

            case 1:
                // Option 1: Add a book.

                addBook();
                // Calls the addBook() function.

                break;
                // Exits this case.

            case 2:
                // Option 2: Display books.

                displayBooks();
                // Calls the displayBooks() function.

                break;
                // Exits this case.

            case 0:
                // Option 0: Exit the program.

                std::cout << "Exiting...\n";
                // Displays an exit message.

                break;
                // Exits the switch statement.

            default:
                // Executes when an invalid option is entered.

                std::cout << "Invalid choice.\n";
                // Displays an invalid-choice message.
        }

    } while (choice != 0);
    // Repeats the menu until the user selects 0.

    return 0;
    // Ends the program successfully.
}