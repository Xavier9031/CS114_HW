#include <iostream>
#include <string>
using namespace std;

//convert table
const int Dec[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
const string Rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

int main() {
    int a;
    string Ans = "";
    while(cin >> a){//input
        for (int i = 0; a > 0; i++){//run all table until a == 0
            while (a >= Dec[i]){
                Ans += Rom[i], a -= Dec[i];
            }
        }
        cout << Ans << endl;//output
        Ans = "";//reset
    }
} 