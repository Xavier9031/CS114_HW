#include <iostream>
#include <exception>
using namespace std;

// int 、 char
int main() {
    try {
        if (5 < 0) {
            throw 5;
        }
        throw 'a';
    }
    catch (const int e) {//int
        cout << e << endl;
    }
    catch (...) {//other
        cout << "something wrong" << endl;
    }
     
    return 0;
}