#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>
double guessnumtut;
double randomnumbertut;
extern int menu();
int randomnumtut();


class Tutorial{
    public:

static int tutorialstart(){
    system("clear");
        std::cout << "Put in a number, pick any one 1-100:";
        std::cin >> guessnumtut;
         if(guessnumtut  >= 100){
            system("clear");
            std::cout << "The number is over 100!" << std::endl;
            sleep(1);
            system("clear");
            tutorialstart();
}
                else{
                 randomnumtut();  
  }
         return(0);
};

static void tutorialwin(){
     std::cout << '\n' << "You won!\n" << "You win $100 everythime you get the number.\n" << "You get more money the closer you are to it.\nIf you get the number, jackpot!" << std::endl;
     std::cout << "Press enter to continue...";
     std::cin.ignore();
     std::cin.get();
     menu();
};

static void randomnumtut(){
   srand(time(0));
 do{
  usleep(230000);
  randomnumbertut = rand() % 100 + 1;
  std::cout << '\r' << randomnumbertut << std::flush;
  --cycleamnt;
  } while(cycleamnt != 0);
  std::cout << '\r' << guessnumtut << std::endl;
  tutorialwin();
};

}; // END OF CLASS
