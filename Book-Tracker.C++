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

                // will first make user save a book while they are in this case 
                do {

                    Book.SaveBook();

                    std::cout << "Title: " << Book.title << std::endl;
                    std::cout << "Author: " << Book.author << std::endl;

                    Books.push_back(Book); 

                    std::cout << "This is what you put for the save." << std::endl;
                    Books[0].DisplayBook(); // displays what user put from that specific book

                    


                } while (false);
 
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