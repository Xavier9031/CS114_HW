//1082414張恆達 程二 HW1_01 

#include <string>
#include<ctime>
#include<iomanip>
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
    void setCurrentTime(){
    	time_t now = time(0);
		  tm *ltm = localtime(&now);
		  hour = ltm->tm_hour;
		  minute = ltm->tm_min;
		  second = ltm->tm_sec;
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
