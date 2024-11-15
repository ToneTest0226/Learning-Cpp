#include <curl/curl.h>
#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>
#include <stdlib.h>
//send requests to a pltw server, doing this for a class beacause mit app inventor is rotting my brain more than helping. 
double randomnumber;

CURL *curl;
CURLcode res;
curl = curl_easy_init();

int randomnum();
 srand(time(0));
    randomnumber = rand() % 9999 + 1000;

int main(){
    randomnum();
    std::cout << randomnumber;
}


