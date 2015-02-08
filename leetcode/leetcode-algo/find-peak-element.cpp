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
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		int result = 0; 
		
        int size = num.size();

		for(int i=0;i<size;i++){
			
			int a,b,c;
			
			
			//Setup B
			b = num[i];
			
			
			//Setup A
			if(i==0){ a = INT_MIN; } 
			else { a = num[i-1]; }
			
			//Setup C
			if(i == size-1){ c = INT_MIN; }
			else { c = num[i+1]; }
			
			
			//ensure A<B>C
			if(b>a && b>c) { result = i; }
		}
		
		return result;
    }
};

void test(int* arr,int size, Solution s,int expectedResult){
	
	vector<int> input (arr, arr + size);
	
	int output = s.findPeakElement(input);
	
	cout<<"Expected Value:"<<expectedResult<<"\tActual Value:"<<output<<endl;
	assert(expectedResult == output);
	
}

int main(int argc, char *argv[]) {
	
	Solution s;
		
	test((int[]){1,2,1,1}, 4, s, 1);	
	test((int[]){1,1,3,2}, 4, s, 2);		
	test((int[]){1,2,2,3}, 4, s, 3);	
	test((int[]){1,1,2,2,3,2}, 6, s, 4);	
	
}