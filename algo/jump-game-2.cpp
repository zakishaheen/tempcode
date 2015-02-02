#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <cassert>

using namespace std;
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
class Solution {
	//can optimize using memoization here.
public:

	int jumpR(int A[],int n, int current){
		
		if(current >= n-1){ return 0;} 
		
		int min = INT_MAX;
		
		for(int i=A[current]; i>=1; i--){
			int result = jumpR(A,n,current+i);
			if(result<min) min = result;
		}
		
		return 1 + min;
	}	
	
    int jump(int A[], int n) {  
		return jumpR(A,n,0);
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	int ret;
	
	ret = s.jump((int[]){2,3,1,1,4}, 5);
	assert(2 == ret);
	
	ret = s.jump((int[]){2,1,1,1,4}, 5);
	assert(3 == ret);
		
		
	ret = s.jump((int[]){1,4}, 2);
	assert(1 == ret);
}