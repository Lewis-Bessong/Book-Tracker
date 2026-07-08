#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals; 
using namespace std::chrono;

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

            do { // Genre 
            
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

                //invalid input conditionals (genre)
                if (!(std::cin>>genre)) { // invalid varible that was inputted

                    std::cout << "INVALID: INPUT NUMBER" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    continue;
                } else if (genre < 1 || genre > 10) { // User didnt enter the available options 

                    std::cout << "INVALID: Please enter the options that are available" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                    continue;
                } else {

                    break;
                }

            } while (true);            

            do { // Pages

                std::cout << "Pages: ";

                if (!(std::cin >> pages)) {

                    std::cout << "INVALID: INPUT NUMBER" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    continue;
                } else {

                    break;
                }

            } while (true);
            
            do { // Progress + Rating
                std::cout << "Progress (Input #)\n" ;
                std::cout << "--------------------\n";
                std::cout << "1. Plan to Read\n";
                std::cout << "2. Curretly Reading\n";
                std::cout << "3. Completed Book" << std:: endl;
                std::cout << "Enter Here: ";

                if (!(std::cin >> progress)) { // for non number input 

                    std::cout << "INVALID INPUT: INPUT NUMBER" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    continue;
                } else if (progress < 1 || progress > 3) { // for input other than 1,2 or 3 

                    std::cout << "INVLAID INPUT: Enter the options that are available" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    continue;
                } else { // valid input

                    if (progress == 3) { // does rating if 3

                        do { // Rating 

                            std::cout << "Rating (1 = really bad, 10 = really good): ";

                            if (!(std::cin >> rating)) { // for non number input

                                std::cout << "INVALID INPUT: ENTER A NUMBER" << std::endl;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        
                                continue;
                            } else if (rating < 1 || rating > 10) { // for input thats out of the 1-10 range

                                std::cout << "INVALID INPUT: Enter a number within 1-10" << std::endl;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                continue;
                            } else { // valid input

                                break;
                            }

                        } while (true);

                    } else if (progress == 1 || progress == 2) { // skips rating if not 3


                        break;
                    }

                    break; // to get out of loop
                }

            } while (true);


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
    
    // ======= USER INTERACTION ======

    auto two_seconds = 2s; // duration of 2 seconds
    std::cout << "Hello !" << std::endl;

    std::this_thread::sleep_for(two_seconds); // program stops for 2s

    std::cout << "Welcome to....." << std::endl;

    std::this_thread::sleep_for(two_seconds);

    std::cout << "The Book Tracker !" << std::endl;

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

                                myFile << "Self Help/Philosophy (9)" << std::endl;
                            } else if (Books[i].genre == 10) { // Other/Multiple

                                myFile << "Other/Mutiple (10)" << std::endl;
                            }
                            
                            // Pages
                            myFile << "Pages: " << Books[i].pages << std::endl;

                            // Progress + Rating condtionals logic
                            myFile << "Progress: ";
                            if (Books[i].progress == 1) {

                                myFile << "Plan To Read (1)" << std::endl;
                                break;
                            } else if (Books[i].progress == 2) {

                                myFile << "Currently Reading (2)" << std::endl;
                                break; 
                            } else if (Books[i].progress == 3) {

                                myFile << "Completed Book (3)" << std::endl;
                                myFile << "Rating (1-10): " << Books[i].rating << std::endl;
                                break;
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

                        for (int i = 0; i < Books.size(); i++) { // testing file within loop to see the flow
                            
                            myFile.open("books.txt", std::ios::app); {
                                if (myFile.is_open()) {
                                
                                    // add some info that comes from what the user stored within the loop 
                                    myFile << "------------------------" << std::endl;
                                    myFile << "Title: " << Books[i].title << std::endl;
                                    myFile << "Author: " << Books[i].author << std::endl;

                                    // Genre
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

                                        myFile << "Self Help/Philosophy (9)" << std::endl;
                                    } else if (Books[i].genre == 10) { // Other/Multiple

                                        myFile << "Other/Mutiple (10)" << std::endl;
                                    }
                                    
                                    // Pages
                                    myFile << "Pages: " << Books[i].pages << std::endl;

                                    //progess
                                    myFile << "Progress: ";
                                    if (Books[i].progress == 1) {

                                        myFile << "Plan To Read (1)" << std::endl;
                                    } else if (Books[i].progress == 2) {

                                        myFile << "Currently Reading (2)" << std::endl;
                                    } else if (Books[i].progress == 3) {

                                        myFile << "Completed Book (3)" << std::endl;
                                        myFile << "Rating (1-10): " << Books[i].rating << std::endl;
                                    }

                                    myFile.close();
                                    
                                }
                            }

                        }

                        break;
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

                // in progess

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


//Progress + Rating Conditonals
                                    myFile << "Progress: ";
                                    if (Bookprogress == 1) { // for if user is planning reading

                                        myFile << "Plan To Read (1)" << std::endl;
                                        break;
                                    } else if (Bookprogress == 2) { // for if user is still reading

                                        myFile << "Currently Reading (2)" << std::endl;
                                        break; 
                                    } else if (Bookprogress == 3) { // for if user has completed it so it also outputs their rating

                                        myFile << "Completed Book (3)" << std::endl;
                                        myFile << "Rating (1-10): " << Bookrating << std::endl;
                                        break;
                                    }
                                        
                                    



for (int i = 0; i < Books.size(); i++) {



*/