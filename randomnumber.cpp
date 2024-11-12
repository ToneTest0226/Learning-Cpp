#include "gamble.h"
#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>


double money = 100;
int cycleamnt = 10;
int guessnum;

int guess(){
  std::cout << "Take a guess" << '\n';
  std::cin >> guessnum;
  return std::round(guessnum);
  Gamble::randomnum();
    return 0;
 }

int distance();


int main(){
guess();    
return 0;
}