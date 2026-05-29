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
 
        void Mode() { // see to make text layout better/readable. (future change to switch statements for efficeincy)

            std::string mode;

            do { // does block of code first

                //question
                std::cout << "Please choose desired mode.\n";
                std::cout << "1. Save\n";
                std::cout << "2. View/Change\n";
                std::cout << "3. End" << std::endl;

                //get info
                std::cout << "\nMode ('1', '2', '3'): ";
                std::cin >> mode;

                // check if valid 
                if (mode == "1") {

                    // Save method
                    Save();
                    // after method need to find way to loop into this conditional again for user.
                    break;
                } else if (mode == "2") {

                    View();

                    break;
                } else if (mode == "3") {

                    std::cout << "Goodbye." << std::endl;
                    break;
                    std::exit;
                } else {

                    std::cout << "Invlaid. Please enter the available options by their #. \n\n";
                    std::cin.ignore(); // to ignore leftover characters 
                    std::cin.clear(); // clearing bad input
                    

                }

            } while (true); // will always loop based on 'true' but 'break' within conditionals exit loop
            
        }

        void Save() { // find out how to store user info about books

            //need something to save and keep data fromo user
            //data structure might be needed to keep organize
            //something to do with class objects 

        }; 

        void View() {

            //something to do with class objects
            // think of way that user could change their data input
            // data struc might be needed
            // might need to use string tools from string header

        };

    private:

    //container for user books
    std::vector<std::string> Book = {"1", "2", "3"};

};


main(){

 BookTracker Tracker;

 std::cout << "Welcome to your Book Tracker." << std::endl;

 Tracker.Mode();

}
