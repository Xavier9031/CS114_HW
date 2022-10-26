////Hw2_01

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

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
      cout  << faces[face] << '_' << suits[suit] << ", ";
    }
};

class DeckOfCard {
  private:
    vector<Card> cards;
    int currentCard;
  public:
    DeckOfCard(){
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
          cards.push_back(Card(i,j));
      }
      void shuffle(){
        srand(time(NULL));
        for(int i = 0; i < 52; i++){
          int index = i + rand()%(52-i);
          swap(cards[index], cards[i]);
        }
      }
      void show(){
        for(int i = 0; i < 52; i++){
          cards[i].toString();
        }
    }
};

int main(){   
  DeckOfCard cards;
  cards.shuffle();
  cout << "Player:" << endl;
  cards.show();
}


