#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string convert(string s, int nRows);
};

string Solution::convert(string s, int nRows){
	string result;
	
	for(int i=0;i<nRows;i++){
		
	}
	
	return result;
}

int main(int argc, char *argv[]) {
	string input = "PAYPALISHIRING";
	Solution s;
	string output = s.convert(input,3);
	
	cout<<output<<endl;
}