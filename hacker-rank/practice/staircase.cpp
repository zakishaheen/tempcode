#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/staircase

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	
	int N = 0;
	cin>>N;
	
	for(int i = 0; i < N; i++){
		
		for(int j = N - 1; j > i; j--){
			cout<<" ";
		}
		for(int k = (N - 1) - i; k < N; k++){
			cout<<"#";
		}
		cout<<endl;
	}
	return 0;
}

