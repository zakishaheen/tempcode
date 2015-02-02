#include <iostream>
#include <cassert>

using namespace std;

/*
Questions: 

Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
*/


class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
		
		for(long i=5;n/i>=1;i *= 5){
			result += n/i;
		}
		
		return result;	
    }
};



int main(int argc, char *argv[]) {
	Solution s;
	
	assert(0 == s.trailingZeroes(3));
	assert(1 == s.trailingZeroes(5));
	assert(3 == s.trailingZeroes(15));
	assert(7 == s.trailingZeroes(30));
}