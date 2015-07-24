#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;



string getInputFromStdIn(){
	string result;
	cin>>result;
	return result;
}

void convertTo24Hours(string t){
	
	int hours = stoi(t.substr(0,2), nullptr);
	int minutes = stoi(t.substr(3,2), nullptr);
	int seconds = stoi(t.substr(6,2), nullptr);
	string peher = t.substr(8,2);
	
	if(peher.compare("AM") == 0 && hours==12){
		hours = 0;
	}
	if(peher.compare("PM") == 0 && hours!=12){
		hours += 12;
		hours = hours % 24;
	}
	
	printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	
	string input = getInputFromStdIn();
	
	convertTo24Hours(input);
	
	return 0;
}

