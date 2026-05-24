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

            // invalid input feature needed
            // 

            std::cin.ignore(); // used to clear the buffer of previous '\n' 
            std::cout << "Name: ";
            std::getline(std::cin, Name); // used to read input with spaces 

            std::cout << "Genre: ";
            std::getline(std::cin, Genre); 

            std::cout << "# of Pages: ";
            std::cin >> Pages;

            std::cout << "Book Rating (1-10): ";
            std::cin >> Rating;



            std::cout << "\nBook Name: " << Name << std::endl;
            std::cout << "Genre: " << Genre << std::endl;
            std::cout << "Pages: " << Pages << std::endl;
            std::cout << "Book Rating: " << Rating << std::endl;


            
        }

        void BookView() { // for viewing saved books

            std::cout << "Saved Books" << std::endl;
            //list of saved books started below
        }

        void SystemStop() { //for stoping the program

            std::cout << "Tracker Stopped." << std::endl;
            std::abort; 

        }
    private:
    

};

main() {

// system resources
BookTracker Tracker;
int UserChoice;

// conditional
std::cout << "Welcome to Your Book Tracker!\n\n";

// future options for user later 
std::cout << "1. Save New Book\n"; 
std::cout << "2. View Saved Book\n";
std::cout << "3. Stop Tracker\n\n";

std::cout << "Enter Here: ";
std::cin >> UserChoice;

// conditonal + input error feature

// possible loop will be needed

switch (UserChoice) {

    case 1:
    Tracker.BookSave();
    break;

    case 2: 
    Tracker.BookView();
    break;

    case 3:
    Tracker.SystemStop();
    break;

    default:
    std::cout << "Wrong Input" << std::endl;
}

    return 0;
}


/* Notes 

. Need way to save book and be available to view later 
. code/terminal should match project vision
. possible nested class/ data strutures

*/