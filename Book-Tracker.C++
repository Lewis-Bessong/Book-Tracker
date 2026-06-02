#include <iostream>
#include <string>
#include <vector>

// Book class for what a book needs 
struct Book { // 'struct' to keep everything together regardless of data type
    public: 
        //attributes (traits)
        std::string title; 
        std::string author; 
        std::string genre;  
        std::string progress; 
        int pages;
        int rating;

    private: // nonaccesale in main
};

void Menu() { // Starting menu for user (Seeing what the program can do)  

    std::cout << "Welcome to your Book Tracker.\n";
    std::cout << "-----------------------------\n";
    std::cout << "1. Save New Book\n";
    std::cout << "2. View Saved Book\n";
    std::cout << "3. Stop Book Tracker" << std::endl;
}

main(){
    // variables
    int MenuOption;

    //container for books (stores/organizes data)
    std::vector<Book> Books; //contains objects from the "Book" class

    // Menu output, user input, and conditionals (switch statments)
    do {

        Menu();
        std::cout << "Option: ";
        std::cin >> MenuOption;

        switch (MenuOption) {
            case 1:
                std::cout << "Saving..." << std::endl;
                break;
            case 2:
                std::cout << "Viewing..." << std::endl;
                break;
            case 3:
                std::cout << "Goodbye!" << std::endl;
                std::abort();
                break;
            default:
                std::cout << "WRONG INPUT." << std::endl;
        };

    } while (false); // why does it work when its in false

}

/*
figure out List: 

. find out how after a user input data within 1 object, you go to the next object to save and save it within vector
. 

*/