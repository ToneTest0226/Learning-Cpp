#include <iostream>
#include <string> 
  

int parkinglotnum = 25;
int parkinglot[25] = {
    0, 0, 0, 0, 0,
    0, 2, 1, 1, 2,
    0, 1, 1, 2, 1,
    0, 0, 0, 0, 0,
    0, 1, 2, 2, 1
};
int parkinglotcheck;
int checknum;
int openspace;
int closedspace;
int paved;
void sayit();
int totalspaces;

void checkpark(){
 while (checknum != 25){
  if (parkinglot[checknum] == 2){
    openspace += 1;
  };
   if (parkinglot[checknum] == 1){
    closedspace += 1;
   };
    if (parkinglot[checknum] == 0){
     paved += 1;
    };
checknum += 1;
 };
 sayit();
};

void sayit(){
 std::cout << openspace << " Open Spaces" <<  "\n";
 std::cout << closedspace << " Closed Spaces" << "\n";
 std::cout << paved << " Paved Spaces" << "\n";
 totalspaces = openspace + closedspace + paved;
 std::cout << totalspaces << " Total spaces\n";
};

int main(){
 checkpark();
 return(0);
};