#include "gamble.h"
#include "tutorial.h"
#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>

int StartAns;
double money = 100;
int cycleamnt = 20;
double abdistance;
double guessnum;

void guess(){
  std::cout << "Take a guess from 1-100:";
  std::cin >> guessnum;
  std::round(guessnum);
if(guessnum >= 100){
  system("clear");
  std::cout << "The number is over 100!" << std::endl;
  sleep(1);
  system("clear");
  guess();
}
  else{
  Gamble::randomnum();  
  }
}

class MenuStart{
public:

static int Startmenu(){
 std::cout << "Hello! Welcome to the gambling simulator!" << '\n' << "Do you need a tutorial?" << '\n' << "\n1: Yes" << "\n2: No" << "\n0: Exit" << std::endl;
 std::cout << "(YES/no):";
 std::cin >> StartAns;
 switch(StartAns){
   case 1:
   Tutorial::tutorialstart();
   break;

   case 2:
    guess();
   break;

   case 0:
    exit(0);
   break;

  }  
  return(0);
 };
};

int main(){
MenuStart::Startmenu();
return 0;
}