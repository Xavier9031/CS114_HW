#include <iostream>
#include <exception>
using namespace std;

class Account{
    int money;
    string name;
    public:
    Account(string _n):money(0){
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
        Account a("a");
        Account b("b");
        a.save(-500);//throw out
        Account c("c");//c doesn't be called
    }
    catch(char const* error) {
        cout << error << endl;  
    }
   cout << "===============================\n";//end of program
    return 0;
}