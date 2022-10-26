//1082414張恆達 程二 HW1_03+04

#include <string>
#include<ctime>
#include<iomanip>
#include <iostream>
#include<vector>
using namespace std;

#ifndef TIME_H
#define TIME_H


class Time{
  private:
    int second;
  public:
    Time(int _sec = 0){
    	second = _sec;
    }
    void setTime(){
    	int _time = -1;
    	cout << "Enter time in seconds counting starting from midnight : ";
    	while(1){
  			scanf("%d", &_time);
  			if(_time >= 0){
  				break;
			}else{
				cout << "Error!!!\nPlease enter again : ";
				fflush(stdin);
			}
		}
		second = _time;
    }
    void printUniversal(){
		cout << setfill('0') << setw(2) << ((second/3600)%24) << ':' << setw(2) << (second/60)%60 << ':' << setw(2) << second%60;
    }
    void printStandard(){
		string apm = ((second/3600)%24 < 12) ? "AM" : "PM";
    	cout << setfill('0') << setw(2) << ((((second/3600)%24)==0) ? 12 : (second/3600)%24)<< ":" <<setw(2) << (second/60)%60 <<':' << setw(2) << second%60 << ' ' << apm << endl;
    }
    
};
#endif

