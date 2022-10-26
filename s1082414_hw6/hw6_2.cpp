#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool mycompare(int a, int b) {
    return a > b; // 降序排列
}

template <typename T>
  class List {
    vector<T> elems;
    public:
      void push(T _in){
        elems.push_back(_in);
      };
      void print(vector<T> _elems){
        for(int i = 0; i < _elems.size(); ++i){
          cout << _elems[i] << " " ;
        }
        cout << endl;
      } 
      void print_elems(){
        cout << "Array構造函數:\n";
        for(int i = 0; i < elems.size(); ++i){
          cout << elems[i] << " " ;
        }
        cout << endl;
      }
      void sorting(){
        cout << "排序:\n";
        vector<T> elems_copy = elems;
        sort(elems_copy.begin(), elems_copy.end(), mycompare);
        print(elems_copy);
      }
      void invertiing(){
        cout << "倒置:\n";
        vector<T> elems_copy = elems;
        sort(elems_copy.begin(), elems_copy.end(), mycompare);
        reverse(elems_copy.begin(), elems_copy.end());
        print(elems_copy);
      }
      void searching(T a){
        bool find = false;
        int Pos;
        for(int i = 0; i < elems.size(); ++i){
          if(elems[i] == a){
            find = true;
            Pos = i+1;
            break;
          }
        }
        if(find){
          cout << "是第" << Pos << "個元素" << endl;
        }else{
          cout << "未找到該元素" << endl;
        }
      }
      void summing(){
        T sum = 0;
        for(int i = 0; i < elems.size(); ++i){
          sum += elems[i];
        }
        cout << "求和:\n數組合為:" << sum << endl;
      }
};
int main() {
  cout << "請輸入元素個數:\n";
  int elem_num1,elem_num2,elem_num3;
  cin >> elem_num1 >> elem_num2 >> elem_num3;
  cout << "請輸入int型數組元素:\n";
  List<int> list_int;
  for(int i = 0; i < elem_num1; ++i){
    int temp;
    cin >> temp;
    list_int.push(temp);
  }
  
  list_int.print_elems();

  cout << "int型數組:\n";
  list_int.sorting();
  list_int.invertiing();

  cout << "請輸入要查找的元素:";
  int temp_int;
  cin >> temp_int;
  list_int.searching(temp_int);

  list_int.summing();

  cout << "==========================================" << endl;

  cout << "請輸入double型數組元素:\n";
  List<double> list_double;
  for(int i = 0; i < elem_num2; ++i){
    double temp;
    cin >> temp;
    list_double.push(temp);
  }
  
  list_double.print_elems();

  cout << "double型數組:\n";
  list_double.sorting();
  list_double.invertiing();

  cout << "請輸入要查找的元素:";
  double temp_double;
  cin >> temp_double;
  list_double.searching(temp_double);

  list_double.summing();

  cout << "==========================================" << endl;

  cout << "請輸入float型數組元素:\n";
  List<float> list_float;
  for(int i = 0; i < elem_num3; ++i){
    float temp;
    cin >> temp;
    list_float.push(temp);
  }
  
  list_float.print_elems();

  cout << "double型數組:\n";
  list_float.sorting();
  list_float.invertiing();

  cout << "請輸入要查找的元素:";
  float temp_float;
  cin >> temp_float;
  list_float.searching(temp_float);

  list_float.summing();
} 