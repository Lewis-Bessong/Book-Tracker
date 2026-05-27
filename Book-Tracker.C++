#include <iostream>
#include <string>
#include <vector>
#include <map>


struct BookTracker { // 'struct' to keep everythign together regardless of type
    public: 

        std::string title; 
        std::string author;
        std::string genre;
        int pages;
        int rating;
 
        // for user

        void Mode() {

            std::cout << "Please choose desired mode.\n";
            std::cout << "1. Save\n";
            std::cout << "2. View/Change\n";
            std::cout << "3. End" << std::endl;
            
            std::cout << "\nMode ('1', '2', '3'): ";


        }

        // for tracker

    private:

    std::vector<std::string> Book = {"1", "2", "3"};


};




main(){

BookTracker Tracker;
BookTracker User;

std::cout << "Welcome to your Book Tracker." << std::endl;

Tracker.Mode();


}


/* Notes 

. Need way to save book and be available to view later 
. code/terminal should match project vision
. possible nested class/ data strutures

*/