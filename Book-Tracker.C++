#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

// Book class for what a book needs 
struct BookBlueprint { // 'struct' to keep everything together regardless of data type
    public: 
        //attributes (traits)
        std::string title; 
        std::string author; 
        std::string genre;  
        int progress; 
        int pages;
        int rating;
        std::string SaveOption; // for user input towards save method

        void BookInput() { // what user will type info into
                
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Title: ";
            std::getline(std::cin, title);

            std::cout << "Author: "; 
            std::getline(std::cin, author);

            std::cout << "Genre: ";
            std::getline(std::cin, genre);

            std::cout << "Pages: ";
            std::cin >> pages;

            // conditionals for progress r needed
            std::cout << "Progress (Input #)\n" ;
            std::cout << "--------------------\n";
            std::cout << "1. Plan to Read\n";
            std::cout << "2. Curretly Reading\n";
            std::cout << "3. Completed Book" << std:: endl;
            std::cout << "Enter Here: ";
            std::cin >> progress;

            // conditional for rating (depending on progress)
            if (progress == 1) {

                
            } else if (progress == 2) {

            } else if (progress == 3) {

                std::cout << "Rating (1 = really bad, 10 = really good): ";
                std::cin >> rating;
            }

        };

};

void Menu() { // Starting menu for user (Seeing what the program can do)  

    std::cout << "Book Tracker Menu.\n";
    std::cout << "-----------------------------\n";
    std::cout << "1. Save New Book\n";
    std::cout << "2. View Saved Book\n";
    std::cout << "3. Stop Book Tracker" << std::endl;
    std::cout << "Option: "; // where input will take place
}

void SaveMode() {

    std::cin.clear();
    std::cout << "Book Saved.\n";
    std::cout << "------------\n";
    std::cout << "Save another book?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No" << std::endl;
    std::cout << "Option: ";

}

main(){


    // variables
    int MenuOption;
    int SaveOption;

    //container for books (stores/organizes data)
    std::vector<BookBlueprint> Books; //contains objects from the "Book" class

    //Object
    BookBlueprint Book;

    // File to store saved books
    std::fstream myFile;
    // overrides info everytime, this is temporary
    myFile.open("books.txt", std::ios::out);
    if (myFile.is_open()) {

        myFile.close();
    }
    
    // Looped Menu output, user input, and conditionals (switch statments)
    do {

        // Starting menu
        Menu();
        std::string DummyInput; // used to repeat program
        
        // checks for non-number input
        if (!(std::cin >> MenuOption)) { 

            std::cout << "WRONG INPUT. (Enter a Number)" << std:: endl;
            std::cin.clear(); // resets fail 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

            continue; // still goes to the switch statment 
        }
        
        // switch statments for what user inputs from menu
        switch (MenuOption) { 
             
            case 1: // save

                Book.BookInput(); // User inputs info           
                Books.push_back(Book); // book gets stored

                // User decision to continue saving books 
                do {

                    SaveMode(); // if they want to save again

                    if (!(std::cin >> SaveOption)) { // check for non number input 

                        std::cout << "WRONG INPUT (ENTER NUMBER)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

                        continue;
                    }

                    while (SaveOption == 1){ // if 1, keeps repeating this code 

                        Book.BookInput(); //input
                        Books.push_back(Book); //store

                        // constantly repeats (condtionals inside break out of loop)
                        do {

                            SaveMode();

                            if (!(std::cin >> SaveOption)) { // check for non number input 

                                std::cout << "WRONG INPUT (ENTER NUMBER)" << std::endl;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

                                continue;
                            } 

                            if (SaveOption == 2) {

                                break;
                            } else if (SaveOption == 1) {

                                Book.BookInput(); //input
                                Books.push_back(Book); //store

                                continue;
                            } else {

                                std::cout << "WRONG INPUT" << std::endl;
                            }
                        } while (true);
                      
                    } if (SaveOption == 2) { // breaks out while loop 

                        break;
                    } else { //invalid input occurs

                        std::cout << "WRONG INPUT" << std::endl;
                        continue;
                    }

                } while (SaveOption != 1 && SaveOption != 2);

                // adds info into seprate file
                for (int i = 0; i < Books.size(); i++) { // repeats based on how many user saved

                    // new info gets added to file
                    myFile.open("books.txt",std::ios::app); // append mode
                    if (myFile.is_open()) { 

                        myFile << "Saved Books." << std::endl;
                        myFile << "-------------------------" << std::endl;
                        myFile << "Title: " << Books[i].title << std::endl; 
                        myFile << "Author: " << Books[i].author << std::endl;
                        myFile << "Genre: " << Books[i].genre << std::endl;
                        myFile << "Pages: " << Books[i].pages << std::endl;
                        myFile << "Progress: ";
                        if (Books[i].progress == 1) {

                            myFile << "1 (Plan To Read)" << std::endl;
                            break;
                        } else if (Books[i].progress == 2) {

                            myFile << "2 (Currently Reading)" << std::endl; 
                            break;
                        } else if (Books[i].progress == 3) {

                            myFile << "3 (Completed Book)" << std::endl;
                            myFile << "Rating(1-10): " << Books[i].rating << std::endl;
                            break;
                        }

        
                        myFile.close();
                    }
        
                }

                std::cout << "Input Anything For Menu: "; 
                std::cin >> DummyInput;
                                                        
                break;

            case 2: // user chooses to view 

                // prints what they just saved
                for (int i = 0; i < Books.size(); i++) { 

                    std::cout << "Frequntly Saved Books" << std::endl;
                    std::cout << "-------------------------" << std::endl;
                    std::cout << "Title: " << Books[i].title << std::endl; 
                    std::cout << "Author: " << Books[i].author << std::endl;
                    std::cout << "Genre: " << Books[i].genre << std::endl;
                    std::cout << "Progress: ";
                    if (Books[i].progress == 1) {

                        std::cout << "1 (Plan To Read)" << std::endl;
                        break;
                    } else if (Books[i].progress == 2) {

                        std::cout << "2 (Currently Reading)" << std::endl;
                        break; 
                    } else if (Books[i].progress == 3) {

                        std::cout << "3 (Completed Book)" << std::endl;
                    }

                    std::cout << "Pages: " << Books[i].pages << std::endl;

                    // For Rating depending on book progress
                    if (Books[i].progress == 1) {

                        break;
                    } else if (Books[i].progress == 2) {
                    
                        break;
                    } else if (Books[i].progress == 3) { // if completed then show rating

                        std::cout << "Rating (1-10): " << Books[i].rating << std::endl;
                    }

                }
                
                // prints what they saved in the past
                for (int i = 0; i < Books.size(); i++) {

                    // add read mode file in here
                    
                }



                break; 
            case 3: // user chooses to end program
                // finished 
                std::cout << "Goodbye!" << std::endl;
                std::exit(0); // end program immediatly with success
                break;
            default: // user puts something else than 1, 2, 3
                //finished
                std::cout << "WRONG INPUT." << std::endl;

        }

    } while (MenuOption != 3); // do block will be repeated if this condition happens

}

/*

// For Rating depending on book progress
                        if (Books[i].progress = 1) {
                            break;
                            
                        } else if (Books[i].progress = 2) {
                            break;
                                               
                        } else if (Books[i].progress = 3) { // if completed then show rating

                            myFile << "Rating (1-10): " << Books[i].rating << std::endl;
                        }

*/