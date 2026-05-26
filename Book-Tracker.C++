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
        void TrackerMode() { // what usr will use to choose modes within tracker (conditionals)
            
            

            // Add loop conditionals (case, if else)
            // Find out if you can call another method within a method in the same class
        }


        void BookSave() { // for storing books

            // invalid input feature needed
             

            std::cin.ignore(); // used to clear the buffer of previous '\n' 
            std::cout << "Name: ";
            std::getline(std::cin, Name); // used to read input with spaces 

            std::cout << "Genre: ";
            std::getline(std::cin, Genre); 

            std::cout << "# of Pages: ";
            std::cin >> Pages;

            std::cout << "Book Rating (1-10): ";
            std::cin >> Rating;

            //to check if everything is good after inpiut
            std::cout << "\nBook Name: " << Name << std::endl;
            std::cout << "Genre: " << Genre << std::endl;
            std::cout << "Pages: " << Pages << std::endl;
            std::cout << "Book Rating: " << Rating << std::endl;      
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



    return 0;
}


/* Notes 

. Need way to save book and be available to view later 
. code/terminal should match project vision
. possible nested class/ data strutures

*/