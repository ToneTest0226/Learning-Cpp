#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 
#include <cstdlib>
// chatgpt helped me make this concept, im doing it but it def did help with the idea.
double xx;
double yy;
int z;


int choose(){
 int selection;
 std::cout << "Select a way to use your numbers." << '\n' <<
"1 = Multiplication" << '\n' <<
"2 = Division" << '\n' <<
"3 = Addition" << '\n' <<
"4 = Subtraction" << '\n'
;


 std::cin >> selection;

 switch (selection){
    case 1:
    system("clear");
    std::cout << "Your number is: " << xx * yy << '\n';
    break;

    case 2:
    system("clear");
    std::cout << "Your number is: " << xx / yy << '\n';
    break;

    case 3:
    system("clear");
    std::cout << "Your number is: " << xx + yy << '\n';
    break;

    case 4:
    system("clear");
    std::cout << "Your number is: " << xx - yy << '\n';
    break;

    default:
    std::cout << "Selection not known, choose again" << '\n';
    choose();
    break;
 };
return 0;
};

void setnumbers(){
 std::cout << "First number:";
 std::cin >> xx;
 std::cout << '\n' << "Second number:";
 std::cin >> yy; 
 system("clear");
 choose();
}

int main(){
 setnumbers();
return 0;
}
