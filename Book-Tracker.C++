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

            int mode;

            std::cout << "Please choose desired mode.\n";
            std::cout << "1. Save\n";
            std::cout << "2. View/Change\n";
            std::cout << "3. End" << std::endl;

            std::cout << "\nMode ('1', '2', '3'): ";
            std::cin >> mode;

            switch(mode) {

                case 1: // add save method 

                    std::cout << "Getting Program for saving book..." << std::endl;
                    break;
                case 2: // add view method

                    std::cout << "Getting Program for editing books..." << std::endl;
                    break;
                case 3: //add time stop then end program after

                    std::cout << "Stopping Program..." << std::endl;
                    break;

                default: 
                
                // found out how to aks question again and repeat
                do { 

                    std::cout << "\nWrong Input. (Enter just '1', '2'..)" << std::endl;
                    std::cin.clear(); //clear error flag 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // disregard bad input

                } while (false);

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