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
        int genre;  
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

            // Genre list
            std::cout << "Enter # for genre\n";
            std::cout << "-------------------\n";
            std::cout << "1. Romance\n";
            std::cout << "2. Fantasy\n";
            std::cout << "3. Mystery/Crime\n";
            std::cout << "4. Horror\n";
            std::cout << "5. Thriller/Suspense\n";
            std::cout << "6. Science Fiction (Sci-Fi)\n";
            std::cout << "7. Historical Fiction\n";
            std::cout << "8. Historical\n";
            std::cout << "9. Self-Help/Philosophy\n";
            std::cout << "10. Other/Multiple" << std::endl;
            std::cout << "Genre: ";
            std::cin >> genre;  

            std::cout << "Pages: ";
            std::cin >> pages;

            
            std::cout << "Progress (Input #)\n" ;
            std::cout << "--------------------\n";
            std::cout << "1. Plan to Read\n";
            std::cout << "2. Curretly Reading\n";
            std::cout << "3. Completed Book" << std:: endl;
            std::cout << "Enter Here: ";
            std::cin >> progress;

            // conditional for rating (depending on progress)
            if (progress == 1) {
                //empty
            } else if (progress == 2) {
                //empty
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

    // ======= BOOK TRACKER TOOLS ========

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
    
    // ======== SYSTEM LOGIC ========

    // Looped Menu output, user input, and conditionals (switch statments)
    do {

        std::string DummyInput; // used to repeat program

        // Starting menu
        Menu();
        
        // checks for non-number input
        if (!(std::cin >> MenuOption)) { 

            std::cout << "WRONG INPUT. (Enter a Number)" << std:: endl;
            std::cin.clear(); // resets fail 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

            continue; // still goes to the switch statment 
        }
        
        // switch statments for what user inputs from menu
        switch (MenuOption) { 
             
            case 1: // ===== SAVE OPTION =====

                Book.BookInput(); // User inputs info           
                Books.push_back(Book); // book gets stored (short term)

                // info gets stored in file (long term)
                for (int i = 0; i < Books.size(); i++) { 
 
                    myFile.open("books.txt", std::ios::app); {
                        if (myFile.is_open()){

                            myFile << "-------------------------" << std::endl; // for readability
                            myFile << "Title: " << Books[i].title << std::endl; 
                            myFile << "Author: " << Books[i].author << std::endl;

                            //Genre Condtionals logic
                            myFile << "Genre: "; 
                            if (Books[i].genre == 1) { // Romance

                                myFile << "Romace (1)" << std::endl;
                            } else if (Books[i].genre == 2) { // Fantasy 

                                myFile << "Fantasy (2)" << std::endl;
                            } else if (Books[i].genre == 3) { // Mystery/Crime

                                myFile << "Mystery/Crime (3)" << std::endl;
                            } else if (Books[i].genre == 4) { // Horror

                                myFile << "Horror (4)" << std::endl;
                            } else if (Books[i].genre == 5) { // Thriller/Suspens

                                myFile << "Thriller/Suspense (5)" << std::endl;
                            } else if (Books[i].genre == 6) { // History Fiction

                                myFile << "Historical Fiction (6)" << std::endl;
                            } else if (Books[i].genre == 7) { // Historical

                                myFile << "Historical (7)" << std::endl;
                            } else if (Books[i].genre == 8) { // Sci Fi

                                myFile << "Science Fiction/Sci-Fi (8)" << std::endl;
                            } else if (Books[i].genre == 9) { // Self Help/ Philosphy

                                myFile << "Self Gelp/Philosophy (9)" << std::endl;
                            } else if (Books[i].genre == 10) { // Other/Multiple

                                myFile << "Other/Mutiple (10)" << std::endl;
                            }
                            
                            
                            // Progress condtionals logic
                            myFile << "Progress: ";
                            if (Books[i].progress == 1) {

                                myFile << "Plan To Read (1)" << std::endl;
                                break;
                            } else if (Books[i].progress == 2) {

                                myFile << "Currently Reading (2)" << std::endl;
                                break; 
                            } else if (Books[i].progress == 3) {

                                myFile << "Completed Book (3)" << std::endl;
                            }

                            myFile << "Pages: " << Books[i].pages << std::endl;

                            // For Rating depending on book progress
                            if (Books[i].progress == 1) {

                                break;
                            } else if (Books[i].progress == 2) {
                    
                                break;
                            } else if (Books[i].progress == 3) { // if completed then show rating

                                myFile << "Rating (1-10): " << Books[i].rating << std::endl;
                            }                         
                            myFile.close();
                        }

                    }
                }

                // ===== LOOPED SAVE OPTION/LOGIC ===== 
                do {

                    SaveMode(); // if they want to save again

                    if (!(std::cin >> SaveOption)) { // check for non number input 

                        std::cout << "WRONG INPUT (ENTER NUMBER)" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous bad input

                        continue;
                    }

                    while (SaveOption == 1){ // if 1 (continue saving), keeps repeating this code 

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

                    } if (SaveOption == 2) { // breaks out while loop if want to stop saving 

                        break;
                    } else { //invalid input occurs

                        std::cout << "WRONG INPUT" << std::endl;
                        continue;
                    }

                } while (SaveOption != 1 && SaveOption != 2);

                // used to go back to menu 
                std::cout << "Input Anything For Menu: "; 
                std::cin >> DummyInput;
                                                        
                break;

            case 2: // ===== VIEW OPTION ===== 

                // prints what they just saved
                for (int i = 0; i < Books.size(); i++) { 

                    std::cout << "-------------------------" << std::endl;
                    std::cout << "Books Saved Right Now" << std::endl;
                    std::cout << "-------------------------" << std::endl;
                    std::cout << "Title: " << Books[i].title << std::endl; 
                    std::cout << "Author: " << Books[i].author << std::endl;


                    //Genre Condtionals logic
                    std::cout << "Genre: "; 
                    if (Books[i].genre == 1) { // Romance

                        std::cout << "Romace (1)" << std::endl;
                    } else if (Books[i].genre == 2) { // Fantasy 

                        std::cout << "Fantasy (2)" << std::endl;
                    } else if (Books[i].genre == 3) { // Mystery/Crime

                        std::cout << "Mystery/Crime (3)" << std::endl;
                    } else if (Books[i].genre == 4) { // Horror

                        std::cout << "Horror (4)" << std::endl;
                    } else if (Books[i].genre == 5) { // Thriller/Suspens

                        std::cout << "Thriller/Suspense (5)" << std::endl;
                    } else if (Books[i].genre == 6) { // History Fiction

                        std::cout << "Historical Fiction (6)" << std::endl;
                    } else if (Books[i].genre == 7) { // Historical

                        std::cout << "Historical (7)" << std::endl;
                    } else if (Books[i].genre == 8) { // Sci Fi

                        std::cout << "Science Fiction/Sci-Fi (8)" << std::endl;
                    } else if (Books[i].genre == 9) { // Self Help/ Philosphy

                        std::cout << "Self Gelp/Philosophy (9)" << std::endl;
                    } else if (Books[i].genre == 10) { // Other/Multiple

                        std::cout << "Other/Mutiple (10)" << std::endl;
                    }


                    // Progress condtionals logic
                    std::cout << "Progress: ";
                    if (Books[i].progress == 1) {

                        std::cout << "Plan To Read (1)" << std::endl;
                        break;
                    } else if (Books[i].progress == 2) {

                        std::cout << "Currently Reading (2)" << std::endl;
                        break; 
                    } else if (Books[i].progress == 3) {

                        std::cout << "Completed Book (3)" << std::endl;
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

                    std::cout << "------------------" << std::endl; // for readability
                }
                
                // prints what they saved in the past
                for (int i = 0; i < Books.size(); i++) {

                    // add read mode file in here
                    
                }

                break; 
            case 3: // ===== STOP PROGRAM OPTION =====
                 
                std::cout << "Goodbye!" << std::endl;
                std::exit(0); // end program immediatly with success
                break;
            default: // ===== INVALID INPUT CASE =====

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