#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//切割用
const vector<string> split(const string &str, const char &delimiter) {
    vector<std::string> result;
    stringstream ss(str);
    string tok;
    while (getline(ss, tok, delimiter)) {
        tok = tok.assign(tok.begin(), tok.end()-1);
        result.push_back(tok);
    }
    return result;
}

//各種圖案
void print_0_0(){
  cout<<"       *\n      ***\n  ***********\n   *********\n    *******\n   *********\n  ***********\n      ***\n       *\n";
}
void print_0_1(){
  cout<<"       *\n      * *\n  *****  ****\n   *       *\n    *     *\n   *       *\n  ****   ****\n      * *\n       *\n";
}
void print_1_0(){
  cout<<"   *\n  ***\n *****\n*******\n";
}
void print_1_1(){
  cout<<"   *\n  * *\n *   *\n*******\n";
}
void print_2_0(){
  cout<<"  *\n ***\n*****\n ***\n  *\n";
}
void print_2_1(){
  cout<<"  *\n * *\n*   *\n * *\n  *\n";
}

int main() {
  //輸入
  cout << "Input:" << endl;
  string _in;
  getline(cin , _in);

  //預處理
  _in.append(",");
  vector<string> ret = split(_in, ' ');
  vector<string> ret_rev = ret;

  //順序同步
  for(int i = 0 ; i < ret.size(); ++i){
    sort(ret_rev[i].begin(), ret_rev[i].end());
  }

  //比較印出相同
  cout << "Output:\n";
  vector<string> ret_row = ret;
  vector<string> ret_copy = ret_rev;
  for(int i = 0 ; i < ret_row.size();){
      string temp = ret_copy[i];
      for(int l = 0 ; l < ret_copy.size() ;){
        if(temp == ret_copy[l]){
          cout << ret_row[l] << " ";
          ret_row.erase(ret_row.begin() + l);
          ret_copy.erase(ret_copy.begin() + l);
          continue;
        }
        ++l;
      }
      cout << endl;
  }

  //找圖形
  int shape = -1; //star:0 ; triangle:1 ; diamond:2
  int hole = -1;//solid:0 ; hollow:1 ;
  string shape_str, hole_str; 
  for(int i = 0 ; i < ret_rev.size(); ++i){
    if(ret_rev[i] == "arst"){
      shape = 0;
      shape_str = "-star";
    }else if(ret_rev[i] == "aegilnrt"){
      shape = 1;
      shape_str = "-triangle";
    }else if(ret_rev[i] == "addimno"){
      shape = 2;
      shape_str = "-diamond";
    }else if(ret_rev[i] == "dilos"){
      hole = 0;
      hole_str = "-solid";
    }else if(ret_rev[i] == "hlloow"){
      hole = 1;
      hole_str = "-hollow";
    }
  }
  

  //印出圖形
  cout << "Graph:" << shape_str << hole_str << endl;
  if(shape == 0 && hole == 0){print_0_0();}
  else if(shape == 0 && hole == 1){print_0_1();}
  else if(shape == 1 && hole == 0){print_1_0();}
  else if(shape == 1 && hole == 1){print_1_1();}
  else if(shape == 2 && hole == 0){print_2_0();}
  else if(shape == 2 && hole == 1){print_2_1();}



} 
