#include <iostream>
#include <string>

// This is the online book tracker, a place for where users can store there books after they have read them
// this book tracker has a book wish list, favorites list, and scaling system.

// list, vector, class, just think of a data structure

class BookTracker {
    public:
        std::string Name;
        std::string Genre;
        int Pages; 
        int Rating;

};

main() {
    std::string NameInput;

    std::cout << "Book Name: ";
    std::cin >> NameInput;

 
    BookTracker Tracker; 
    
    Tracker.Name = NameInput;
    
    std::cout << "Book Name = " << Tracker.Name << std::endl; 



    return 0;
}


/* Notes 

. develop class
. code/terminal should match project vision
. possible nested class/ data strutures

*/