#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#ifndef CARDS_H
#define CARDS_H

string suits[4] = {"clubs", "spade", "heart", "diamond"};
string faces[13] = { "1","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

class Card {
  private:
    int suit, face;
  public:
    Card(int s,int f){
      suit = s;
      face = f; 
    }
    void toString(){
      cout  << faces[face] << '_' << suits[suit];
    }
};
#endif
