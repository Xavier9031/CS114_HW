////Hw2_02
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
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
    vector<Card> deck;
    int currentCard;
  public:
    DeckOfCard(){
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
          deck.push_back(Card(i,j));
      }
    void shuffle(){
        srand(time(NULL));
        for(int i = 0; i < 52; i++){
          int index = i + rand()%(52-i);
          swap(deck[index], deck[i]);
        }
      }
    void show(int num_Players, int n){
        for(int i = (52/num_Players)*n; i < (52/num_Players)*(n+1); i++){
          deck[i].toString();
        }
        cout << endl;
    }
    vector<Card> get_deck(){
    	return deck;
	}
};

int main(){   
	cout << "How many Player?(1,2,4)\n-> ";
	int num_Players;
	vector<string> players_name;
	DeckOfCard cards;
  	cards.shuffle();
  	string temp_name;
  	
	do{
		cin >> num_Players;
		if (num_Players!=1 && num_Players!=2 && num_Players!=4){
			cout << "Error! Please enter again\n-> ";
		}
	}
	while(num_Players!=1 && num_Players!=2 && num_Players!=4);
	
	for(int i = 1; i <= num_Players; i++){
		cout << "Player " << i << " Name?\n-> ";
		cin >> temp_name;
		players_name.push_back(temp_name);
	}
	
	cout << "\nTotal " << num_Players <<" Player\n";
	for(int i = 0; i < num_Players; i++){
		cout << "\nPlayer " << i+1 << " (" << players_name[i] <<"):\n";
		cards.show(num_Players,i);
	}
//  	DeckOfCard cards;
//  	cards.shuffle();
//  	cout << "Player:" << endl;
//  	cards.show();
}


