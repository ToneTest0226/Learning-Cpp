// A friend wants me to figure out how to make an app to ping a ubisoft ip. I need to figure out how to get it.
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
#include <sstream>

int amntoftimes = 2;
int SendReq();
auto start = std::chrono::system_clock::now();
auto stop = std::chrono::system_clock::now();

int SendReq(){
    system("ping google.com -c 4 -q > ping.txt");
    return(0);
}

int main(){
    SendReq();
    return(0);
}