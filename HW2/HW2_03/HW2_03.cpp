////Hw2_03
#include <iostream>
using namespace std;

//in C++ std libary
//void *operator new(size_t);     //allocate an object => 開一個空間 
//void *operator delete(void *);    //free an object => 刪一個空間 
//
//void *operator new[](size_t);     //allocate an array => 多用一個空間存此陣列的大小 
//void *operator delete[](void *);    //free an array => 依據陣列的大小刪空間 
class test{
	private:
		int var;
		static int count;
	public:
		test(){
			var = count++;
			cout << "struct object " << var << endl;
			
		}
		~test(){
			count--;
			cout << "distruct object " << var << endl;
		}
};

int test::count = 0;

void next(char _case){
	cout << "\n=================== CASE "<<_case <<" ==================\n\n";
}

int main(){
	next('A');
	
	//new
	test *a = new test();
	//delete
	delete a;

	next('B');
	
	//new[]
	class test *b = new class test[3];
	//delete[]
	delete []b;
	
	next('C');
	
//	//new
//	test *c = new test();
//	//delete[]
//	delete []c;
	
	next('D');
	
	//new[]
	class test *d = new class test[3];
	//delete
	delete d;
	
	return 0;
}
