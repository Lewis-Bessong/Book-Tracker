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
        std::string SaveOption; // for user input towards save method

        void BookInput() { // what user will type info into

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

        void SaveBook() {
  
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

void SaveMode() {

    std::cin.clear();
    std::cout << "Book Saved.\n";
    std::cout << "------------\n";
    std::cout << "Save another book?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No" << std::endl;
    std::cout << "Option: ";

}

main(){
    
    // variables
    int MenuOption;
    int SaveOption;

    //container for books (stores/organizes data)
    std::vector<BookBlueprint> Books; //contains objects from the "Book" class

    //Object
    BookBlueprint Book;
    
    // Looped Menu output, user input, and conditionals (switch statments)
    do {

        // Starting menu
        Menu();
        
        // checks for non-number input
        if (!(std::cin >> MenuOption)) { 

            std::cout << "WRONG INPUT. (Enter a Number)" << std:: endl;
            std::cin.clear(); // resets fail 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

            continue; // still goes to the switch statment 
        }
        
        // switch statments for what user inputs from menu
        switch (MenuOption) { 
             
            case 1: 
                //save

                Book.BookInput(); // User inputs info           
                Books.push_back(Book); // book gets stored

                // User decision to continue saving books 
                do {

                    SaveMode(); // if they want to save again

                    if (!(std::cin >> SaveOption)) { // check for non number input 

                        std::cout << "WRONG INPUT (ENTER NUMBER)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

                        continue;
                    }

                    while (SaveOption == 1){ // if 1, keeps repeating this code 

                        Book.BookInput(); //input
                        Books.push_back(Book); //store

                        // constantly repeats (condtionals inside break out of loop)
                        do {

                            SaveMode();

                            if (!(std::cin >> SaveOption)) { // check for non number input 

                                std::cout << "WRONG INPUT (ENTER NUMBER)" << std::endl;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

                                continue;
                            } 

                            if (SaveOption == 2) {

                                break;
                            } else if (SaveOption == 1) {

                                Book.BookInput(); //input
                                Books.push_back(Book); //store

                                continue;
                            } else {

                                std::cout << "WRONG INPUT" << std::endl;
                            }
                        } while (true);
                      
                    } if (SaveOption == 2) { // breaks out while loop 

                        break;
                    } else { //invalid input occurs

                        std::cout << "WRONG INPUT" << std::endl;
                        continue;
                    }

                } while (SaveOption != 1 && SaveOption != 2);
        
                // posibbly something to do here for lopping back to menu 
                continue;

            case 2: // user chooses to view 


                std::cout << "Viewing..." << std::endl;
                break; 
            case 3: // user chooses to end program
                // finished
                std::cout << "Goodbye!" << std::endl;
                std::exit(0); // end program immediatly with success
                break;
            default: // user puts something else than 1, 2, 3
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