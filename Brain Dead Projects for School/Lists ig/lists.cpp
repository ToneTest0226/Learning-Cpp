#include <iostream>
#include <vector> 
#include <string>
#include <unistd.h>
// #include <windows.h> if on windows, replace unistd!

std::vector<std::string> onedlist;  
int vecsize;
int currentindex;

void sayit(){
    onedlist.push_back("Words");
    onedlist.push_back("are");
    onedlist.push_back("cool!");
    vecsize = onedlist.size();
    while(currentindex != vecsize){
     std::cout << onedlist[currentindex] << "\n"; 
     sleep(1); 
     currentindex++;
    };

// Start reverse of string, can be done with any length!

   currentindex = vecsize;
   while(currentindex != -1){
   std::cout << onedlist[currentindex] << "\n";
   sleep(1);
   currentindex--;  
 }
}
int main(){
    sayit();
    return(0);
};