#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	bool isSign(char x){ return x=='-' || x=='+'; }
	bool isNumber(char x){ return (x>='0' && x<='9'); }
	
    int atoi(const char *str) {
	
		int result = 0; 
		
		int len = strlen(str);
		
		if(len==0) return 0;
		
		int firstNumIndex = -1;
		int lastNumIndex = -1;
		int counter = 0;
		int sign = 1; 
				
		while(str[counter]==' '){ counter++; }//pick all whitespaces
		if(isSign(str[counter])) { if(str[counter]=='-') sign = -1;  counter++; } // expect a sign
		if(isNumber(str[counter])){ firstNumIndex = counter; } //expect a number and kickstart machine
		while(isNumber(str[counter])){ lastNumIndex = counter;  counter++; } //keep expecting numbers and keep track
		if(firstNumIndex==-1) result = 0; //couldnt find a starting numeral
		if(firstNumIndex!=-1 && firstNumIndex==lastNumIndex) result = sign * (str[firstNumIndex] - '0'); //found  single digit
		
		
		if(firstNumIndex<lastNumIndex){
			int joe = 0; 
			
			int digits = lastNumIndex - firstNumIndex; 
			if(digits >= 9){
				if(sign==1) result =  INT_MAX;
				else result = sign*INT_MAX;
			} 
			
			for(int j=lastNumIndex;j>=firstNumIndex;j--){
				
				int cur = str[j] - '0';
				if(sign==-1){
					
					if(sign * (result + cur * pow(10, joe)) <= INT_MIN){
						result = INT_MIN;
						break;
					}
				}else{
					if((result + cur * pow(10, joe)) >= INT_MAX){
						result = INT_MAX;
						break;
					}
				}
				result += cur * pow(10, joe);
				joe++;
				
			}
			result = sign*result;
			
		}
		
        return result;
    }
};




int main(int argc, char *argv[]) {
	Solution s;
	
	cout<<" :"<<s.atoi(" ")<<endl;
	cout<<":"<<s.atoi("")<<endl;
	cout<<" 4:"<<s.atoi(" 4")<<endl;
	cout<<"-1:"<<s.atoi("-1")<<endl;
	cout<<"1:"<<s.atoi("1")<<endl;
	cout<<" 44:"<<s.atoi(" 44")<<endl;
	cout<<" 431a:"<<s.atoi(" 431a")<<endl;
	cout<<" -431a:"<<s.atoi(" -431a")<<endl;
	cout<<" +431a:"<<s.atoi(" +431a")<<endl;
	cout<<"2147483648:"<<s.atoi("2147483648")<<endl;
	cout<<"-2147483647:"<<s.atoi("-2147483647")<<endl;
	
}