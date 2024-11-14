#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>

double randomnumber;
extern double money;   
extern int cycleamnt;
extern double guessnum;
extern double abdistance;

extern int menu();

class Gamble{
 public:

static int moneyearned(){
  std::cout << "not done!" << std::flush;
  menu();
  return(0);

};

static int distance(){
     abdistance = std::abs(randomnumber - guessnum);
      moneyearned();
     return(0);
};

static int randomnum(){
   money -= 10; 
   srand(time(0));
 do{
  usleep(230000);
  randomnumber = rand() % 100 + 1;
  std::cout << '\r' << randomnumber << std::flush;
  --cycleamnt;
  } while(cycleamnt != 0);
   distance();
 return 0;
};


};

