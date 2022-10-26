#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    long long int a;
    string str;
    stringstream ss;
    bool negative = false;

    while(cin >> a){ //input
        if(a < 0){negative = true; a *= (-1);} //a < 0?
        ss << a; ss >> str;//int to string
        reverse(str.begin(),str.end());// reverse string
        while(a % 10 == 0){//pop 0
            str = str.substr(1);
            a /= 10;
        }
        if(negative){//output
            cout << '-' << str << endl;
        }else{
            cout << str << endl;
        }
        ss.clear();str.clear();negative = false;//reset
    }
} 