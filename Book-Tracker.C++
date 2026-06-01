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

//container for books


main(){
    Book User; //object of class book

    User.title == "Harry Potter";  // attributes of that object
    
    std::vector<Book> Books{User}; // using vector as a dynamic array to hold instances(objects) of the class "Book".

    std::cout << Books[0];
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