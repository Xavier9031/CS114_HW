#include <iostream>
#include <exception>
#include <experimental/optional>
using namespace std;

class Account{
    int money;
    string name;
    public:
    Account(string _n, int _m){
        if(_m < 0){
            throw "Fail to creat Account";
        }
        money = _m;
        name = _n;
        cout << "This is constructor : " << name << "\n" ;
    }
    ~Account(){
        cout << "This is destructor  : " << name << "\n" ;
    }
    void save(int _m){
        if(_m < 0 ){
            throw "Negative saving";
        }else{
            money += _m;
        }
    }
};

int main() {
    try {
        Account a("a", -100);
    }
    catch(char const* error) {
        cout << error << endl; 
    }
    
    cout << "===============================\n";//end of program
    return 0;
}
