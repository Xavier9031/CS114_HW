////Hw2_03
#include <iostream>
using namespace std;

//in C++ std libary
//void *operator new(size_t);     //allocate an object => �}�@�ӪŶ� 
//void *operator delete(void *);    //free an object => �R�@�ӪŶ� 
//
//void *operator new[](size_t);     //allocate an array => �h�Τ@�ӪŶ��s���}�C���j�p 
//void *operator delete[](void *);    //free an array => �̾ڰ}�C���j�p�R�Ŷ� 
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
