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
        void BookEval() {

            std::cout << "Book Name: ";
            std::cin >> Name;

            std::cout << "Book is " << Name << std::endl;

        }

};

main() {

BookTracker Tracker;

Tracker.BookEval();

    return 0;
}


/* Notes 

. develop class
. code/terminal should match project vision
. possible nested class/ data strutures

*/