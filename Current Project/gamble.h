#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>
#include <stdlib.h>

double randomnumber;
extern double money;   
extern int cycleamnt;
extern double guessnum;
extern double abdistance;
double k = 0.1;
double jackpot = 100;
extern int dfd;

extern int menu();

class Gamble{
 public:

static int distance(){
     abdistance = std::abs(randomnumber - guessnum);
      moneyearned();
     return(0);
};

static int moneyearned(){
  double earned = jackpot * std::exp(-k * abdistance);
  earned = std::round(earned);
   if (dfd == true){
    earned = earned * 2;
     money += earned;  
     std::cout << '\n' << "You won $"<< earned << "!" << std::endl;
    menu();
  }else {
    money += earned;
    std::cout << '\n' << "You won $"<< earned << "!" << std::endl;
    menu(); 
   }
   
  return(0);
};



static int randomnum(){
  cycleamnt = 20;
   if (dfd == true){
    money -= 20;
    } else{
      money -=10;
    }
   srand(time(0));
 do{
  usleep(230000);
  randomnumber = rand() % 100 + 1;
  system("clear");
  std::cout << "Your number is:" << randomnumber << std::flush;
   --cycleamnt;
  } while(cycleamnt != 0);
   distance();
 return 0;
};


};

