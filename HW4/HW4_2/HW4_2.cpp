#include <iostream>
#include <string>
using namespace std;

int main(){
	string input;
	int length;
	cout << "Welcome to input" << endl;
    getline(cin,input);
    length = input.length();
    
    for(int i = 0; i <= length/2; ++i){
    	//print space
    	for(int l = length/2 - i; l > 0 ; --l){
    		cout << ' ';
		}
		//print element
		for(int l = i; l <= 2*i ; ++l){
			cout << input[l];
		}
		for(int l = 2*i-1; l >= i ; --l){
			cout << input[l];
		}
		cout << endl;
	}
	return 0;
}
