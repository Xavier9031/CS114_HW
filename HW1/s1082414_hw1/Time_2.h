#include <string>
#include<ctime>
//1082414張恆達 程二 HW1_02+04 

#include<iomanip>
#include<vector>
using namespace std;

#ifndef TIME_H
#define TIME_H


class Time{
  private:
    int hour;
    int minute;
    int second;
  public:
    Time(int _hr = 0, int _min = 0, int _sec = 0){
    	hour = _hr;
    	minute = _min;
    	second = _sec;
    }
    bool checktime(int _hr, int _min, int _sec){
    	return((_hr>=0&&_hr<23)&&(_min>=0&&_min<100)&&(_sec>=0&&_sec<100));
    }
    void setTime(){
    	int _hr = -1, _min = -1, _sec = -1;
    	cout << "Current time [hour(0~22):minute(0~99):second(0~99)] = ";
    	while(1){
  			scanf("%d:%d:%d", &_hr , &_min ,&_sec);
  			if(checktime(_hr, _min, _sec)){
  				break;
			}else{
				cout << "Error!!!\nPlease enter again : ";
				fflush(stdin);
			}
		}
    	if(_sec >= 60){
    		second = _sec%60;
    		_min++;
		}else{
			second = _sec;
		}
    	if(_min >= 60){
    		minute = _min%60;
    		_hr++;
		}else{
			minute = _min;
		}
    	hour = _hr;
    }
    void printUniversal(){
		cout << setfill('0') << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second;
    }
    void printStandard(){
		string apm = (hour < 12) ? "AM" : "PM";
    
    cout << setfill('0') << setw(2) << ((hour==0 || hour==12) ? 12 : hour%12)<< ":" <<setw(2) << minute <<':' << setw(2) << second << ' ' << apm << endl;
    }
    
};
#endif
