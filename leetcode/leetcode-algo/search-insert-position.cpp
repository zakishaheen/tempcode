#include <iostream>
#include <cassert>

using namespace std;

class Solution {
	public:
		int searchInsert(int A[], int n, int target) {
			int result = -1;
			int i = 0;
			for(i=0; i<n; i++){
				if(A[i] == target || A[i] > target){
					result = i;
					break;
				}
			}
			
			if(result == -1){
				result = i;
			}
			
			return result; 
		}
	};

int main(int argc, char *argv[]) {
	Solution s; 
	
	assert(0 == s.searchInsert((int[]){}, 0, 1)); //empty array. 
	
	assert(1 == s.searchInsert((int[]){1}, 1, 2));//single element, doesnt exists. 
	assert(0 == s.searchInsert((int[]){1}, 1, 1));//single element, exists. 
	
	
	assert(1 == s.searchInsert((int[]){0,1}, 2, 1)); //two elements, exists. 
	
	assert(2 == s.searchInsert((int[]){1,3}, 2, 4)); //two elements, doesn't exist - tail. 
	assert(1 == s.searchInsert((int[]){1,3}, 2, 2)); //two elements, doesn't exist - middle. 
	assert(0 == s.searchInsert((int[]){1,3}, 2, 0)); //two elements, doesn't exist - head. 
	
	//given test cases
	assert(2 == s.searchInsert((int[]){1,3,5,6}, 4, 5)); 
	assert(1 == s.searchInsert((int[]){1,3,5,6}, 4, 2)); 
	assert(4 == s.searchInsert((int[]){1,3,5,6}, 4, 7)); 
	assert(0 == s.searchInsert((int[]){1,3,5,6}, 4, 0)); 
}