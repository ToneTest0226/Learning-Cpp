#include <stdlib.h>
#include <iostream>
#include <string> 
#include <vector> 
#include "colourmod.h"

//0 = empty square 
//1  = orange, end square 
//2 = red, blocked square 
//3 = green, start square
int checkarray = 0;
int isstart;
int isend;
int row;


int Path[25] = {
    1,0,0,0,0,
    2,0,0,0,0,
    0,0,0,0,2,
    0,2,0,0,0,
    0,0,0,0,3
            };

void sayit(){
Color::Modifier def(Color::FG_DEFAULT);
Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier blue(Color::FG_ORANGE);
  while(checkarray != 25){
   if(checkarray % 5 == 0 && checkarray != 0 || checkarray % 5 == 5){
     std::cout << "\n"; 
     row++;
    }
    if(Path[checkarray] == 0){ //empty
     std::cout << def << Path[checkarray];
    };
    if(Path[checkarray] == 1){ //end
     std::cout << blue << Path[checkarray];
     isend++;
    };
    if(Path[checkarray] == 2){ //blocked
     std::cout << red << Path[checkarray];
    };
    if(Path[checkarray] == 3){ //start
     std::cout << green << Path[checkarray];
     isstart++;
    };
    checkarray++;
  };

};

void checkshortestpath(){

};

int main(){
    sayit();
    std::cout << "\n";
    return(0);
}