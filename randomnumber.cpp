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
int cycleamnt = 20;
double guessnum;

int guess(){
  std::cout << "Take a guess:";
  std::cin >> guessnum;
  std::round(guessnum);
  Gamble::randomnum();  
  return 0;
 }

int distance();


int main(){
guess();  
std::cout << money;
return 0;
}