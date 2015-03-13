#include <iostream>
#include <cassert>

using namespace std;

class Solution {
	public:
		
		
		
		void shift_once(int nums[], int n){
			int pickedTemp;
			
			for(int i=1;i<n; i++){
				if(i==0){
					pickedTemp = nums[i];
				}
				else if(i==(n-1)){
					nums[i] = pickedTemp;
				}else{
					nums[i] = nums[i+1];
				}
			}
		}
		void rotate(int nums[], int n, int k) {
			for(int i=0; i<k; i++){
				shift_once(nums, n);
			}
			
			for(int i=0;i<n;i++){
				cout<<nums[i]<<",";
			}
			
			cout<<endl;
		}
	};
	
int main(int argc, char *argv[]) {
	Solution s;
	
	int array0[] = {}; //empty
	
	int array1[] = {1}; //single digit
	int array2[] = {1,2};
	int array10[] = {1,2,3,4,5,6,7,8,9,10};
	
	//rotate empty
	
	s.rotate(array0, 0, 0);
	s.rotate(array0, 0, 1);
	s.rotate(array0, 0, 5);
	
	
	s.rotate(array1, 1, 0);
	s.rotate(array1, 1, 1);
	s.rotate(array1, 1, 5);
	
	
	s.rotate(array2, 2, 0);
	s.rotate(array2, 2, 1);
	s.rotate(array2, 2, 5);
	
	s.rotate(array10, 10, 5);
	s.rotate(array10, 10, 4);
	s.rotate(array10, 10, -1);
	//rotate single 0 times.
	//rotate single 1 times.
	//rotate single 5 times. 
	
	// rotate 2 one time
	//rotate two zero times
	//rotate two 5 times. 
	
	//rotate 10
	//negative rotation?
}