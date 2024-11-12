#include <iostream>
#include <memory>

class NewNDel{
public:
  static int newndelt(){
   int* newt;
    newt = new int;
    *newt = 128;
  std::cout << *newt << std::endl;
  delete newt;
  newt = nullptr;
  return(0);
};

  static void newsub(){
    std::cout << "This is a sub of the class!" << '\n';
};
};
