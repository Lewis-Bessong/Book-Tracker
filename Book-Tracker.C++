#include <iostream>
#include <string>
#include <vector>

struct Book { // Book class for what a book needs and 'struct' to keep everything together regardless of data type
    public: 
        std::string title; 
        std::string author; 
        std::string genre;  
        std::string progress; 
        int pages;
        int rating;

    private: // nonaccesale in main
};

main(){

 std::cout << "Welcome to your Book Tracker." << std::endl;

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