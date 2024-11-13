#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>

int randomnumber;
extern double money;   
extern int cycleamnt;
class Gamble{

public:

static int randomnum(){
 money -= 10;
 do{
  usleep(340000);
  system("clear");
  srand(time(0));
  randomnumber = rand() % 100 + 1;
  std::cout << randomnumber << '\n';
  --cycleamnt;
  } while(cycleamnt != 0);

 return 0;
};


};

class Tutorial{



};