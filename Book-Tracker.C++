#include <iostream>
#include <string>
#include <algorithm> 


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
        int UserMode;

        // methods
        void Mode() { // what user will use to choose modes within tracker (conditionals)
            // Find out if you can call another method within a method in the same class
            // Add loop conditionals (case, if else)


            BookTracker Tracker; 

            std::cout << "\nOption: ";
            std::cin >> UserMode;

            switch(UserMode) {
                case 1: 

                    std::cout << "\n";
                    BookSave();
                
                    break;
                case 2:

                    std::cout << "\n";
                    BookView();

                    break;
                case 3:

                    std::cout << "\n";
                    SystemStop();

                default:

                    std::cout << "\nWrong Input" << std::endl;
            }
            
        }

        void BookSave() { // for storing books
            
        }

        void BookView() { // for viewing saved books

            std::cout << "Saved Books" << std::endl;

            //list of saved books started below
            // research if this method needs list, array, jsut some type of data struc
        }

        void SystemStop() { //for stoping the program

            // method is good

            std::cout << "Tracker Stopped." << std::endl;
            std::abort; 

        }
    private:

    

};

main() {
    BookTracker Tracker;

    std::cout << "Welcome to your Book tracker." << std::endl;
    std::cout << "1. Save Book" << std::endl;
    std::cout << "2. Track Book" << std::endl; 
    std::cout << "3. Stop Program" << std::endl;
    
    Tracker.Mode();


    return 0;
}


/* Notes 

. Need way to save book and be available to view later 
. code/terminal should match project vision
. possible nested class/ data strutures

*/