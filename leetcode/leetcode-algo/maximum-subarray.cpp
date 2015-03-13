#include <iostream>
#include <cassert>


using namespace std;

class Solution {
	public:
				
		int maxSubArray(int A[], int n) {
			
			int totalSum = 0;
			for(int i = 0; i < n; i++){
				totalSum += A[i];
			}	
			
			cout<<"Total Sum = "<<totalSum<<endl;
			
			int start = 0;
			int end = n - 1;
			
			int currentMaxSum = totalSum;
			
			while(true){
				cout<<"start="<<start<<"\t end="<<end<<endl;
				
				int sumA = currentMaxSum - A[start];
				int sumB = currentMaxSum - A[end];
				
				cout<<"SumA = "<<sumA<<"\t";
				cout<<"SumB = "<<sumB<<"\t";
				if(sumA >= currentMaxSum){
					currentMaxSum = sumA;
					start = start + 1;
					
				}else if(sumB >= currentMaxSum){
					currentMaxSum = sumB;
					end = end - 1;
					
				}else{
					return currentMaxSum; //stop the search. 
				}
			}
			
		}
	};
	
	
int main(int argc, char *argv[]) {
	Solution s;
	int sum = s.maxSubArray((int []){-2, 1, -3, 4, -1, 2, 1, -5, 4}, 9);
	cout<<sum;
//	assert(6 == sum);
}