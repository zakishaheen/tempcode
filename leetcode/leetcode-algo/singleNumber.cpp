#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
	
		unordered_map<int,int> m;
		
		for(int i=0;i<n;i++){
			if(m.end() == m.find(A[i])){
				m[A[i]] = 1;
			}else{
				m[A[i]] = 2;
			}
		}
		
		for(auto i = m.begin(); i!= m.end(); i++){
			if((*i).second==1) return (*i).first;
		}
	}
        
};

int main(int argc, char *argv[]) {
	Solution s;
	cout<<s.singleNumber((int[]){-1}, 1)<<endl;
	cout<<s.singleNumber((int[]){2,2,1}, 3)<<endl;
	cout<<s.singleNumber((int[]){-1,-1,-2}, 3)<<endl;
}