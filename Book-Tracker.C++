#include <iostream>
#include <string>
#include <vector>

// Book class for what a book needs and 
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


main(){

    //container for books (stores/organizes data)
    std::vector<Book> Books {}; // a dyamic array that contain objects of the class "Book"

    //variable for user input
    std::string UserTitle;
    std::string UserAuthor;
    std::string UserGenre;
    std::string UserProgress;

    //user input
    std::cout << "Welcome to the Book Tracker." << std::endl;
    std::cout << "Book title: ";
    std::cin.clear();
    std::getline(std::cin, UserTitle); 
    std::cout << "Author: ";
    std::getline(std::cin, UserAuthor);
    

    //instances from the class "book"
    Book User; //object of book class
     // attributes of that object
    User.title = UserTitle;
    User.author = UserAuthor;
    User.genre = UserGenre;
    User.progress = UserProgress;

    

    // putting object within container (vector)
    Books.push_back(User);  // add object to container 

    
    std::cout << "You put: " << Books[0].title << std::endl; // accessing specsific object and specific attribute

}

// saved code for later

/*

do { // does block of 
                //question
                std::cout << "Please choose an option.\n";
                std::cout << "1. Save\n";
                std::cout << "2. View/Change\n";
                std::cout << "3. End" << std::endl;

                //get info
                std::cout << "\nOption: ";
                std::cin >> option;

                    std::cin.ignore(); // to ignore leftover characters 
                    std::cin.clear(); // clearing bad input
                }

            } while (true); // will always loop based on 'true' but 'break' within conditionals exit loop

*/