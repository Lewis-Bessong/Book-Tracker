#include <iostream>
#include <string>

// This is the online book tracker, a place for where users can store there books after they have read them
// this book tracker has a book wish list, favorites list, and scaling system.

// list, vector, class, just think of a data structure

class BookTracker {
    public:
        // attributes
        std::string Name;
        std::string Genre;
        int Pages; 
        int Rating;

        // methods
        void BookSave() { // for storing books

            std::cout << "Book Name: ";
            std::cin >> Name;

            std::cout << "Book is " << Name << std::endl;

        }

        void BookView() { // for viewing saved books

        }

        void SystemStop() { //for stoping the program

        }



};

main() {

// system resources
BookTracker Tracker;
int UserChoice;

// conditional

std::cout << "Welcome to Your Book Tracker!\n\n";

std::cout << "1. Save New Book\n"; 
std::cout << "2. View Saved Book\n";
std::cout << "3. Stop Tracker\n\n";

std::cout << "Enter Here: ";
std::cin >> UserChoice;


    return 0;
}


/* Notes 

. develop class
. code/terminal should match project vision
. possible nested class/ data strutures

*/