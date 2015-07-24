#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/plus-minus

vector<int> getInput(){
	int N = 0;
	vector<int> result;
		
	cin>>N;
	
	for(int i=0;i<N;i++){
		int A = 0;
		cin>>A;
		result.push_back(A);
	}
		
	return result;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	
	vector<int> As = getInput();
	int positives = 0;
	int negatives = 0;
	int zeros = 0;
	int N = As.size();
	
	for(auto i=As.begin(); i!=As.end(); i++){
		if(*i == 0){
			zeros++;
		}else if(*i < 0){
			negatives++;
		}else{
			positives++;
		}
	}
	
	float pFraction = (float)positives/(float)N;
	float nFraction = (float)negatives/(float)N;
	float zFraction = (float)zeros/(float)N;
	
	printf("%.3f\n%.3f\n%.3f\n", pFraction, nFraction, zFraction);
	
	return 0;
}

