#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <cassert>

using namespace std;

/*
Question:
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/


class Solution {
public:
    int majorityElement(vector<int> &num) {
		
		int result = 0;
		
		map<int,int> frequencyTable;
		
		for(auto element = num.begin(); element != num.end(); element++){
			
			auto elementValue =  *element;
						
			if(frequencyTable[elementValue]==0){
				frequencyTable[elementValue] = 1;
			} 
			else {
				frequencyTable[elementValue] = frequencyTable[elementValue]+1;
			}
			
		}
		
		
		for(auto  combo = frequencyTable.begin();combo != frequencyTable.end(); combo++){
			
			pair<int,int> comboValue = *combo;
			
			int value = comboValue.second;
			
			if(value >= ceil(num.size()/2.0)){
				
				if(value >= result){ 
					result = comboValue.first;
				}
			} 
		}
		
		return result;
    }
};


void test(int* arr,int size, Solution s,int expectedResult){
	
	vector<int> input (arr, arr + size);
	
	int output = s.majorityElement(input);
	
	cout<<"Expected Value:"<<expectedResult<<"\tActual Value:"<<output<<endl;
	assert(expectedResult == output);
	
}

int main(int argc, char *argv[]) {
	Solution s;
	
	test((int[]){1,1,1,2}, 4, s, 1);	
	test((int[]){1,1,3,2}, 4, s, 1);		
	test((int[]){1,2,2,2}, 4, s, 2);	
	test((int[]){1,1,2,2,2,2}, 6, s, 2);	
}