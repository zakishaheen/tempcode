#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>

using namespace std;

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
		3
	 / \
	9  20
		/  \
	 15   7
return its zigzag level order traversal as:
[
	[3],
	[20,9],
	[15,7]
]
*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	
		vector< vector<int> > result;
		
		stack<TreeNode*> stackA;
		stack<TreeNode*> stackB;
		
		int level=0;
		
		stackA.push(root);
		
		
		while(!stackA.empty() || !stackB.empty()){
			
			stack<int> toPick = (level%2==0) ? stackA : stackB; 
			stack<int> toPush = (level%2==0) ? stackB : stackA;
			
			vector<int> internalResult;
			
			while(!toPick.empty()){
				TreeNode *n = toPick.top();
				toPick.pop();
				
				internalResult.push_back(n->val);
				if(level%2==0){
					toPush.push(n->right);
					toPush.push(n->left);
				}else{
					toPush.push(n->left);
					toPush.push(n->right);
				}
			}
			
			result.push_back(internalResult);
			level++;
						
		}
		
		return result; 
        
    }
};


//"{1,2,3,#,#,4,#,#,5}".
// 0 -> 1,2
// 1 -> 3,4
// 2 -> 5,6
TreeNode* createTreeWithArray(int[] A, int size){
	for(int i=0;i<size;i++){
		TreeNode *n = new TreeNode()		
		n->val = A[i];
		n->
	}
	
}
int main(int argc, char *argv[]) {
	
}