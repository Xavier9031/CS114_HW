#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string input, num_str;
    stringstream ss;
    int num, output;
    bool isnone;
    vector <string> output_arr;
    
    cout << "Welcome to input" << endl;
	 
    while(getline(cin,input)){
    	
    	if(input.length() == 0){break;}
    	output = 0;
    	isnone = true;
    	
		for(int i = 0; i <= input.length(); ++i){
			
			if(int(input[i]) >= 48 && int(input[i]) <= 57){
				num_str.append(1, input[i]);
			}
			
			else {	
				if(num_str.length() != 0){
					isnone = false;
				}
				
				ss << num_str; 
				ss >> num;
				
				output += num;
				
				ss.clear();
				num_str.clear();
				num = 0;
			}	
		}
	    //push output
		if(isnone){
			output_arr.push_back("None");
		}else{
			ss << output;
			ss >>  num_str;
			output_arr.push_back(num_str);
			ss.clear();
			num_str.clear();
		}	
	}
	//print
	for(int i = 0 ; i < output_arr.size(); ++i){
		cout << output_arr[i] << endl;
	}
  	
	return 0;
}

