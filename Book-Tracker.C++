#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>


struct BookTracker { // 'struct' to keep everythign together regardless of type
    public: 

        std::string title; 
        std::string author;
        std::string genre;
        int pages;
        int rating;
 
        void Mode() {

            std::string mode;

            std::cout << "Please choose desired mode.\n";
            std::cout << "1. Save\n";
            std::cout << "2. View/Change\n";
            std::cout << "3. End" << std::endl;

            std::cout << "\nMode ('1', '2', '3'): ";
            std::cin >> mode;

            if (mode == "1") {

                std::cout << "Saving book.." << std::endl;
            } else if (mode == "2") {

                std::cout << "Editing book.." << std::endl;
            } else if (mode == "3") {

                std::cout << "Goodbye." << std::endl;
                std::exit;
            } else {

                do{

                    std::cout << "Invalid. Please enter 1, 2, or 3 only." << std::endl;

                    std::cout << "1. Save\n";
                    std::cout << "2. View/Change\n";
                    std::cout << "3. End" << std::endl;

                    std::cout << "\nMode: ";
                    std::cin >> mode;


                } while (mode != "1" || "2" || "3");
            }


            
        }


    private:

    //container for user books
    std::vector<std::string> Book = {"1", "2", "3"};


};




main(){

 BookTracker Tracker;

 std::cout << "Welcome to your Book Tracker." << std::endl;

 Tracker.Mode();

}


/* Notes 

. Need way to save book and be available to view later 
. code/terminal should match project vision
. possible nested class/ data strutures

*/