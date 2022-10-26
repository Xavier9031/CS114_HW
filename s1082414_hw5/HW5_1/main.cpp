#include <iostream>
#include "Member.h"
#include "Gold_mamber.h"
#include "Siver_member.h"
#include "Normal_member.h"
#include "Diamond_member.h"
using namespace std;

int main() {
  int id;
  cout << "Member ID:";
  cin >> id;
  
  switch(membership(id)){
    case 0:
      n_m();
      break;
    case 1:
      s_m();
      break;
    case 2:
      g_m();
      break;
    case 3:
      d_m();
      break;
    default:
      break;
  }
} 