#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//https://www.hackerrank.com/challenges/a-very-big-sum

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	
	int N = 0;
	long long result = 0;
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		int number = 0;
		cin>>number;
		result+=number;
	}
	
	cout<<result;
	
	return 0;
}

