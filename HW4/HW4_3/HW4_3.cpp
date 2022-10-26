#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// bool canTransform(string start, string end) {
//        int n = start.size(), cntL = 0, cntR = 0;
//        for (int i = 0; i < n; ++i) {
//            if (start[i] == 'R') ++cntR;
//            if (end[i] == 'L') ++cntL;
//            if (start[i] == 'L') --cntL;
//            if (end[i] == 'R') --cntR;
//            if (cntL < 0 || cntR < 0 || cntL * cntR != 0) return false;
//        }
//        return cntL == 0 && cntR == 0;
//    }

vector <string> str_vec;



bool search(string input, string goal){
	int len = input.length();
	static bool find = false;
	static int c = 0;

	if (len != goal.length()){
		return false;
	}
	
	cout << "now : " << input << " ; " << c << endl;
	str_vec.push_back(input);c++;
	
	for(int pos = 0 ; pos < len-1; ++pos){
		if((input[pos] == 'R' && input[pos+1] == 'X') || (input[pos] == 'X' && input[pos+1] == 'L')){
			cout << "swap  " << input << "   "<< pos << " : " ;
			swap(input[pos],input[pos+1]);
			cout << input  << " : " << c << endl;
			if(input == goal || find){
				find = true;
				cout << "FUND : " << input << " : " << goal << endl;
				cout << "FOUND!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				return true;
			}	
			search(input, goal);//recrusive
			swap(input[pos],input[pos+1]);
			
		}
	}
	str_vec.pop_back();c--;
	cout << "return" << c-1 << endl;
	
	return false;
}
int main(){
	string start = "RXXLRXRXL";
	string end = "XRLXXRRLX";
	bool ok = search(start,end);
	if(ok){
		cout << "OK" << endl;
		for(int i = 0; i < str_vec.size() ; ++i){
			cout << str_vec[i] << " ->" <<  endl;
		}
		cout << end;
	}else{
		cout << "NOT OK"<< endl;
	}
	
	return 0;
} 
