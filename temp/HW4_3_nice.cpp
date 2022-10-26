#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> str_vec;

bool search(string input, string goal){
	int len = input.length();
	static bool find = false;
	static int c = 0;

	if (len != goal.length()){
		return false;
	}
	str_vec.push_back(input);c++;
	
	for(int pos = 0 ; pos < len-1; ++pos){
		if((input[pos] == 'R' && input[pos+1] == 'X') || (input[pos] == 'X' && input[pos+1] == 'L')){
			swap(input[pos],input[pos+1]);
			if(input == goal || find){
				find = true;
				return true;
			}	
			search(input, goal);//recrusive
			swap(input[pos],input[pos+1]);
		}
	}
	str_vec.pop_back();c--;
	return false;
}
int main(){
	string start = "RXXLRXRXL";
	string end = "XRLXXRRLX";
	cout << "Input: start = \"" << start <<"\", end = \"" << end << "\"" << endl;
	bool ok = search(start,end);
	if(ok){
		cout << "Output: True" << endl;
		cout << "Explanation:" << endl;
		cout << "We con transform start to end follewing these steps:" << endl;
		for(int i = 0; i < str_vec.size() ; ++i){
			cout << str_vec[i] << " ->" <<  endl;
		}
		cout << end;
	}else{
		cout << "Output: False"<< endl;
	}
	return 0;
} 
