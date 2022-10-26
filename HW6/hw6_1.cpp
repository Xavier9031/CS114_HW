#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
  int start, end;
  cin >> start >> end;
  cout << setw(6) << "Decimal" <<setw(8) << "Octal" << setw(14) << "Dexadecimal" << setw(12) << "Character" <<endl;
  for(int i = start; i <= end; ++i){
    cout << dec << showbase << setw(6) << i;
    cout <<setw(8) << oct << showbase << i ;
    cout << setw(14) << hex << showbase << i;
    cout << setw(12) << char(i) <<endl;
  }
} 