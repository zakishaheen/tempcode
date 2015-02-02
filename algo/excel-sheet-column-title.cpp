#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <cassert>

using namespace std;

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {	
		string result; 
		stack<char> t;
		
		while(n > 0){

			int current = n % 26;
			if(current == 0) current = 26;
			
			t.push('A' + (current - 1));
			
			//because we've already calculated one of these for each unit. 
			if(n%26 == 0){ n = n/26; n = n-1; } 
			else{ n = n/26; }
			
		}
		
		
		while(!t.empty()){	
			char n = t.top();
			t.pop();
			result += n;
		}
		
		return result;
    }
	
};


int main(int argc, char *argv[]) {
	Solution s;
	
	assert(0==string("A").compare(s.convertToTitle(1)));
	assert(0==string("B").compare(s.convertToTitle(2)));
	assert(0==string("Z").compare(s.convertToTitle(26)));
	assert(0==string("AA").compare(s.convertToTitle(27)));
	assert(0==string("AB").compare(s.convertToTitle(28)));
	assert(0==string("AZ").compare(s.convertToTitle(52)));
	assert(0==string("BA").compare(s.convertToTitle(53)));
	assert(0==string("BZ").compare(s.convertToTitle(78)));
	assert(0==string("CA").compare(s.convertToTitle(79)));
}




