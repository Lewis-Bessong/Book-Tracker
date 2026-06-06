#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Book class for what a book needs 
struct BookBlueprint { // 'struct' to keep everything together regardless of data type
    public: 
        //attributes (traits)
        std::string title; 
        std::string author; 
        std::string genre;  
        std::string progress; 
        int pages;
        int rating;

        void SaveBook() { // what user will type info into

            std::cin.clear();
            std::cin.ignore();
            std::cout << "Book Title: ";
            std::getline(std::cin, title);
            std::cout << "Book Author: ";
            std::getline(std::cin, author);         

        };

        void DisplayBook() { // used to show what user has typed

            std::cout << "Title: " << title << "\n";
            std::cout << "Authro: " << author << std::endl;
        };

    private: // nonaccesale in main
};

void Menu() { // Starting menu for user (Seeing what the program can do)  

    std::cout << "Book Tracker Menu.\n";
    std::cout << "-----------------------------\n";
    std::cout << "1. Save New Book\n";
    std::cout << "2. View Saved Book\n";
    std::cout << "3. Stop Book Tracker" << std::endl;
    std::cout << "Option: "; // where input will take place
}


main(){
    // variables
    int MenuOption;
    std::string SaveOption;

    //container for books (stores/organizes data)
    std::vector<BookBlueprint> Books; //contains objects from the "Book" class

    //Object
    BookBlueprint Book;

    // Looped Menu output, user input, and conditionals (switch statments)
    do {

        // Starting menu
        Menu();

        if (!(std::cin >> MenuOption)) { // conditional for non-number input

            std::cout << "WRONG INPUT. (Enter a Number)" << std:: endl;
            std::cin.clear(); // resets fail 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

            continue; // still goes to the switch statment 
        }
        
        switch (MenuOption) { // switch statments for what user inputs
            case 1:

                // Save should most likely be outside of loop 

                do {
                    // User inputs info about saved book
                    Book.SaveBook();

                    // saved book gets saved within the vector
                    Books.push_back(Book); 

                    // User decision for whats next
                    std::cin.clear();
                    std::cout << "Book Saved.\n";
                    std::cout << "------------\n";
                    std::cout << "Save another book? (Y/N): ";
                    std::cin >> SaveOption;

                    //conditionals
                    if (SaveOption == "Y" || SaveOption == "y") {

                        std::cout << "Saving...." << std::endl;
                        // in progress
                    } else if (SaveOption == "N" || SaveOption == "n") {

                        std::cout << "Going back to menu..." << std::endl;
                        // find out how to go back to menu without stopping whole program and going to another case
                        //has something to do with breaks, continues, and posibbly loops
                        continue;
                    } else {
                        std::cout << "INVALID INPUT. (only single letter)" << std::endl;
                        // After this code, the program automatically goes to save first
                        // find out how to go back to the question instead
                    }

                } while (SaveOption != "Y" && SaveOption != "y" && SaveOption != "N" && SaveOption != "n");
   
                // posibbly something to do here for lopping back to menu 
                break;

            case 2:
                // add conditionals for what book user wants to see
                // add indexed elements from vector

                std::cout << "Viewing..." << std::endl;
                break;
            case 3:
                // finished
                std::cout << "Goodbye!" << std::endl;
                std::exit(0); // end program immediatly with success
                break;
            default:
                //finished
                std::cout << "WRONG INPUT." << std::endl;

        };

    } while (MenuOption != 1 && MenuOption != 2 && MenuOption != 3); // do block will be repeated if this condition happens

}

/*
figure out List: 

. find out how after a user input data within 1 object, you go to the next object to save and save it within vector
. 

*/