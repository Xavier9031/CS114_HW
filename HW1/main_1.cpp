//1082414張恆達 程二 HW1_01 

#include <iostream>
#include "Time_1.h"
#include <string>
using namespace std;

int main() {
   Time t;

   cout << "The initial universal time is ";
   t.printUniversal();
   cout << "\nThe initial standard time is ";
   t.printStandard();
  
  t.setCurrentTime();

  cout << "\n\nUniversal time after setCurrentTime is ";
  t.printUniversal();
  cout << "\nStandard time after setCurrentTime is ";
  t.printStandard();
  cout << endl;
	  
  return 0;
}
