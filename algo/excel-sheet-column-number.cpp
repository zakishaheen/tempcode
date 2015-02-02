#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <cassert>

using namespace std;

/*
Question:
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/
class Solution {
public:
	int characterToInt(char x){
		return (x - 'A') + 1;
	}
    int titleToNumber(string s) {
		int result = 0;
		
		int lastIndex = s.length() - 1;
				
		for (int rIndex = 0; rIndex <= lastIndex; rIndex++) {
			result += characterToInt(s[lastIndex - rIndex]) * pow(26,rIndex);  //for example, for AZ, we would do Z*(26^0) + A*(26*1)
		}
		
		return result;
        
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	
	assert(1 == s.titleToNumber("A"));
	assert(26 == s.titleToNumber("Z"));
	assert(27 == s.titleToNumber("AA"));
	assert(52 == s.titleToNumber("AZ"));
	assert(53 == s.titleToNumber("BA"));
}