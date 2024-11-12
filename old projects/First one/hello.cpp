#include "newndel.h" 
#include <iostream>
#include <unistd.h>
#include <memory>
#include <any>
#include <string> 

// main is trash, like bad actually
using namespace std;

int x;
int y;
int f;
int s;
int& X = x;
int& Y = y;
int* ptr2 = new int(10);


int test(){
 cout << "Hello, World!" << "\n" << "Number input:";
 cin >> x;
 cout << endl << "Your number:" << x << "\n" << endl;
    return(0);
}

int count(){
 cout << "Enter start:";
 cin >> x;
 do {
   cout << endl << "Count:" << y << endl;
   if(y > x){
    cout << "Number has exceeded! Stopped memory leak!" << endl;
    return 0;
   }
    else{
        y++;
    }

 } while (y != x);
return(0);
}


int test2(){
 if(y > 10 && x > 10){
    cout << "Both lines are above 10" << endl;

} else {
    cout << "One line is not above 10" << endl;
}
return(0);

}

int test3(){
 cout << endl << "First:";
 cin >> f;
 cout << endl << "Second:";
 cin >> s;
 int product = f * s;
 cout << endl << "The product:" << product << endl;
return(0);
 
}

class testclass {
 public:
  int N=5;
  int *pointer = &N;
  void testintheclass() {
   cout << "Multiply " << N * N << endl;
  };
  void testintheclass2() {
    cout << "Pointer=" << *pointer << endl;
  };

  void setXandY() {
    cout << "X:";
    cin >> x;
    cout << "Y:";
    cin >> y;
  };
  
  void reftest() {
    cout << endl << "Refs are: " << "X:" << X << " and " << "Y:" << Y << endl;
  };
  void printb4del() {
    cout << "Before:" << *ptr2 << endl;
    delete ptr2;
    ptr2 = nullptr;
};

 };

// trash
int main(){
test();
cout << "test ran" << endl;
sleep(1);
count();
cout << "count ran" << endl;
sleep(1);
test2();
cout << "number test ran" << endl;
sleep(1);
test3();
cout << "mult test ran" << endl;
sleep(1);
testclass obj;
obj.testintheclass();
sleep(1);
obj.testintheclass2();
sleep(1);
obj.setXandY();
sleep(1);
obj.reftest();
sleep(1);
obj.printb4del();
sleep(1);
NewNDel::newndelt();
NewNDel::newsub();
sleep(1);
cout << endl << "=== end ===" << endl;
return(0);
}