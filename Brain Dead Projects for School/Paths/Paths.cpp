#include <stdlib.h>
#include <iostream>
#include <string> 
#include <vector> 
#include "colourmod.h"

//0 = empty square 
//1  = orange, end square 
//2 = red, blocked square 
//3 = green, start square
//4 = Blue, Path taken
int checkarray = 0;
int isstart;
int isend;
bool starttopleft = false;
bool firstrun = true;
int startpos;
int endpos;
void checkshortestpath();
int currentpos;
int total_length;
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier orange(Color::FG_ORANGE);

int Path[25] = {
    1,0,0,0,0,
    2,0,0,0,0,
    0,0,0,0,2,
    0,2,0,0,0,
    0,0,0,0,3
            };

void sayit(){
  int getlength = sizeof(Path) / sizeof(Path[0]); 
  total_length = getlength - 1;
  
  //std::cout << total_length;
  checkarray = 0;
  if (firstrun == true){
    while(checkarray != 25){
     if(checkarray % 5 == 0 && checkarray != 0 || checkarray % 5 == 5){
      }
      if(Path[checkarray] == 1){ //end
       isend = checkarray;
      }
      if(Path[checkarray] == 3){ //start
        isstart = checkarray;
      }
        checkarray++;
    }
  }else if(firstrun == false){
    checkarray = 0;
    while(checkarray != 25){
     if(checkarray % 5 == 0 && checkarray != 0 || checkarray % 5 == 5){
      std::cout << "\n"; 
      }
     if(Path[checkarray] == 0){ //empty
       std::cout << def << Path[checkarray];
      }
     if(Path[checkarray] == 1){ //end
       std::cout << orange << Path[checkarray];
      }
     if(Path[checkarray] == 2){ //blocked
       std::cout << red << Path[checkarray];
      }
     if(Path[checkarray] == 3){ //start
       std::cout << green << Path[checkarray];
      }
     if(Path[checkarray] == 4){ //path
       std::cout << blue << Path[checkarray];
      }
    checkarray++;
  }
  }else{
    std::cout << "-------------------- SOME TING WONG! --------------------"; 
  }
  //std::cout << "\n";
 //std::cout << total_length;
    if(firstrun == true){
        checkshortestpath();
    }else{
        std::cout << "\n";
        exit(0);
    }
}


void pathfound(){
    if(Path[isend + 1] = 4){
      // currentpos - 1;
      // Path[currentpos] = 4;
       // std::cout << "Path found!";
        firstrun = false;   
        sayit();
    }else if(Path[total_length -1] = 4){
       // currentpos + 1;       
       // Path[currentpos] = 4;
        //std::cout << "Path found!";
        firstrun = false;   
        sayit();
        exit(0);
        }
}

void checkshortestpath(){
    Path[total_length - 1] = 4;
    firstrun = false;
    sayit();
}


int main(){
    sayit();
    std::cout << "\n";
    return(0);
}