#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <cassert>
#include <unordered_map>

using namespace std;

/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		
		//if you want to find an element in an array again and again, convert array into map like:
		
		unordered_map<int, vector<int> > hashmap;
		
		for(int i=0;i<numbers.size();i++){
			vector<int> temp = hashmap[numbers[i]];
			
			if(temp.size()==0){
				vector<int> n;
				n.push_back(i);
				hashmap[numbers[i]] = n;
			}else{
				temp.push_back(i);
				hashmap[numbers[i]] = temp;
			}	
		}
		
		for(int i=0;i<numbers.size();i++){
			
			int remainder = target - numbers[i];
			//notice that checking for existence directly will lead to an object added, hence use find or count
			if(hashmap.find(remainder)!=hashmap.end()){
				
				vector<int> candidate = hashmap[remainder];
				
				if(hashmap.count(remainder) == 1 && candidate[0] == i){ continue; } 
				
				else if(hashmap.count(remainder) == 1 && candidate[0] != i){
				
					vector<int> result;
					
					if(i<candidate[0]){ result.push_back(i + 1); result.push_back(candidate[0] + 1);
					}else{ result.push_back(candidate[0] + 1); result.push_back(i + 1);}
																	return result;
				}else{
					
					for(int k=1;k<candidate.size();k++){
						if(i!=candidate[k]){
							vector<int> result;
							
							if(i<k){ result.push_back(i + 1); result.push_back(candidate[k] + 1);
							}else{ result.push_back(candidate[k] + 1); result.push_back(i + 1); }
						}
					}
				}
				
			}
			
		}
		
    }
};


void test(int* arr,int size, int target, Solution s,int* expectedResult){
	
	vector<int> input (arr, arr + size);
	
	vector<int> output = s.twoSum(input, target);
	
	cout<<"Got:["<<output[0]<<","<<output[1]<<"]"<<endl;
	assert(output[0] == expectedResult[0] && output[1] == expectedResult[1]);
	
}

int main(int argc, char *argv[]) {
	Solution s;
		
	test((int[]){2, 7, 11, 15}, 4, 9, s, (int[]){1,2});
	test((int[]){2, 7, 11, 15}, 4, 13, s, (int[]){1,3});
	test((int[]){-3, 4, 3, 90}, 4, 0, s, (int[]){1,3});	
}