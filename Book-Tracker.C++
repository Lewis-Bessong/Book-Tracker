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

    //container for books (stores/organizes data)
    std::vector<Book> Books; //contains objects from the "Book" class

    Menu();

}

/*
figure out List: 

. find out how after a user input data within 1 object, you go to the next object to save and save it within vector
. 

*/