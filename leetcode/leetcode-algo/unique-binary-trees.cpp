#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3
*/

class Solution {
	unordered_map<int, int> map; //keeps track of number of possibilities of tree of k elements. 
	public:
	int numTrees(int n) {
	    map[0] = 0;
	    map[1] = 1;
			
		if(map.find(n) != map.end()) return map[n];
		
		int sum = 0;
		//its a mirror
		for(int i=1; i <=n/2; i++){	
			if(i > 2){
				sum += (numTrees(i-1) * numTrees(n-i)) * 2;	
			}else{
				sum += numTrees(n-i) * 2;
			}
		}
		
		//the middle condition
		if(n % 2 != 0){
			int x = n/2 + 1;
			sum += pow(numTrees(n-x), 2);
		}
		
		map[n] = sum;
		return sum;
	}
};
	
int main(int argc, char *argv[]) {
	Solution s;
	for(int i=0;i<20;i++)
		cout<<i<<"\t"<<s.numTrees(i)<<endl;
}