#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
		int result = 0;
		
		int length=0;
		
		int multiplier = 0;
		
		
		int index = 0;
		
		for (int i=0;i<s.length();i++) {
			result += multiplier; 
			char x = s[((s.length()-1)-i)];
			int col = (x - 'A') + 1;
			int t = 1; for(int j=0;j<i;j++){ t*=26; }
			result += t*col; 
			

		}
		
		return result;
        
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	
	cout<<s.titleToNumber("BA");
}