#include "Cards.h"
class Card;

class ProxyCard{
	private:
		Card *ptr;
	public:
		ProxyCard(int s,int f):ptr(new Card(s,f)){}
		void toString(){
			ptr->toString();
		}
	
};
