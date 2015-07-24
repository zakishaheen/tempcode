#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/diagonal-difference

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N = 0;
	int result = 0;
	cin>>N;
		
	int lSum = 0; //left diagonal sum
	int rSum = 0; //right diagonal sum
	
	for(int i=0;i<N;i++){ //rows
		for(int j=0;j<N;j++){ //columns
			
			int number = 0;
			
			cin>>number;
			
			if(i==j){
				lSum+=number; 
			}
			
			if(j==((N-1)-i)){
				rSum+=number;
			}	
		}
	}
	
	result = abs(rSum-lSum);
	cout<<result<<endl;

	
	return 0;
}

