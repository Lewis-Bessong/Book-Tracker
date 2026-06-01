#include <iostream>
#include <string>
#include <vector>

struct BookTracker { // 'struct' to keep everything together regardless of type
    public: 

        std::string title; 
        std::string author; // used later
        std::string genre; // used later 
        int pages;
        int rating;
 
        void Program() { // see to make text layout better/readable. (future change to switch statements for efficeincy)

            std::string option;

            do { // does block of code first

                //question
                std::cout << "Please choose an option.\n";
                std::cout << "1. Save\n";
                std::cout << "2. View/Change\n";
                std::cout << "3. End" << std::endl;

                //get info
                std::cout << "\nOption: ";
                std::cin >> option;

                // check if valid 
                if (option == "1") {

                    // Save method
                    Save();
                    // repeats conditional after save method

                } else if (option == "2") {

                    View();

                    break;
                } else if (option == "3") {

                    std::cout << "Goodbye." << std::endl;
                    break;
                    std::exit;
                } else {

                    std::cout << "Invlaid. Please enter the available options by their #. \n\n";
                    std::cin.ignore(); // to ignore leftover characters 
                    std::cin.clear(); // clearing bad input
                }

            } while (true); // will always loop based on 'true' but 'break' within conditionals exit loop

        };

        void Save() { // find out how to store user info about books
            std::cout << "\nPlease enter the info of the book you want to save below." << std::endl;

            //reset input 
            std::cin.ignore();
            std::cin.clear();

            std::cout << "Book Name: "; 
            std::getline(std::cin, title); // to get input with spaces
            std::cout << "# of Pages: ";
            std::cin >> pages;
            std::cout << "Rating (1-10): ";
            std::cin >> rating;

            // to double check input
            std::cout << "Your Book is Saved." << std::endl;
            std::cout << "\nWhat you entered is below." << std::endl;
            std::cout << title << std::endl; 
            std::cout << pages << std::endl;
            std::cout << rating << std::endl;
            std::cout << "\n"; 
        };
        
        void View() {

            //something to do with class objects
            // think of way that user could change their data input
            // data struc might be needed
            // might need to use string tools from string header

        };

    private: // nonaccesale in main

        //varibles 

        //data struc for saving

};

main(){

 BookTracker Tracker;

 std::cout << "Welcome to your Book Tracker." << std::endl;

 Tracker.Program();

}
