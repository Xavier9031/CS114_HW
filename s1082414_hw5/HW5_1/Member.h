#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Member{
  protected:
    int id;
    string name;
    string phone_number;
    int total_transaction;
    //Normal : 0 ;Silver : 1; Gold : 2; Diamond : 3
    int member_type;
  public:
    Member(int _i, string _n, string _p, int _t, int _m){
      id = _i;
      name = _n;
      phone_number = _p;
      total_transaction = _t;
      member_type = _m;
    }
    void print_membership(){
      switch(member_type) {
        case 0:
          cout << "-NORMAL MEMBERSHIP-" << endl;
          break;
        case 1:
          cout << "-SILVER MEMBERSHIP-" << endl;
          break;
        case 2:
          cout << "-GOLD MEMBERSHIP-" << endl;
          break;
        case 3:
          cout << "-DIAMOND MEMBERSHIP-" << endl;
          break;
        default:
          cout << "-ERROR MEMBERSHIP-" << endl;
          break;
      }
      cout << "ID:" << id << endl;
      cout << "Name:" << name << endl;
      cout << "Phone:" << phone_number << endl;
      cout << "Total Transaction:" << total_transaction << endl;
    }
    int get_member_type(){
      return member_type;
    }
};

int membership(int _id){
  Member* A;
  switch(_id) {
    case 111:
      A = new Member(111,"Peter","0901234567",24,0);
      A->print_membership();
      break;
    case 333:
      A = new Member(333,"Tobey","0907654321",45,1);
      A->print_membership();
      break;
    case 555:
      A = new Member(555,"Andrew","0907654123",67,2);
      A->print_membership();
      break;
    case 777:
      A = new Member(777,"Tom","0905674321",93,3);
      A->print_membership();
      break;
    default:
      cout << "NO THIS MEMBER" << endl;
      return(-1);
      break;
    }
  return(A->get_member_type());
}
