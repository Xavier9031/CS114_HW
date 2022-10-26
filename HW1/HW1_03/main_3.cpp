//1082414張恆達 程二 HW1_03+04

#include <iostream>
#include "Time_3.h"
#include <string>
#include<iomanip>
using namespace std;

int main() {
	Time t;
	
	cout << "The initial universal time is ";
	t.printUniversal();
    cout << "\nThe initial standard time is ";
    t.printStandard();
   
	t. setTime();
   
    cout << "\n\nAfter attempting in valid settings: " << "\nUniversal time: ";
    t.printUniversal();
    cout << "\nStandard time: ";
    t.printStandard();
    
	cout << endl;
	  
  return 0;
}
