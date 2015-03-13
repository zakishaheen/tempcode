#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int findSum(string input){
	int result = 0;
	
	for(auto x : input){
		switch (x) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':{
				result += atoi(&x);
				break;
			}
			
			default:
			continue;
				break;
		}
	}
	
	return result;
}

int main(int argc, char *argv[]) {

	string input = "96h11k4959q615948s50922o38h1453ij38w73413d5577lzrqw3780b389750vf100zd29z73j5wh73l6965n85vm77cw10awrjr29265289222238n10013uk10062f9449acbhfgcm35j78q80";
	
	cout<<findSum(input);	
	return 0;
}