//1082414�i��F �{�G HW1_02+04 

#include <iostream>
#include "Time_2.h"
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
