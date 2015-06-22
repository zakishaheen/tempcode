#include <math.h>
#include <assert.h>
#include <iostream>

using namespace std;

//* Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
	
	/*
	Casual solution
	int countNodes(TreeNode* root) {
		if(root==NULL) return 0;
		if(root->left == NULL && root -> right == NULL) return 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
	*/
	
	int findMissing(int currentHeight, int height, TreeNode *t){
		if(!t) return 0;
		
		if(currentHeight == height - 1){
			if(t->right && t->left) return 0;
			if(t->left && !t->right) return 1;
			if(!t->right && !t->left) return 2; 
			else {
				return 0;
			}
			
		}else{
			int l = 0;
			int r = findMissing(currentHeight + 1, height, t->right);
			if(r==2){
				l = findMissing(currentHeight + 1, height, t->left);
			}
			
			return l + r; 
		}
		
	}
	
	int countNodes(TreeNode* root) {
		if(!root) return 0;
		//go extreme left and find the height
		
		TreeNode *temp = root;
		int levels = 0;
		while(temp!=NULL){
			levels++;
			temp = temp->left; 
		} 
		cout<<"Levels = "<<levels<<endl;
		//now scan from right to find the missing elements, if any. 
		int subtraction = 0; //assuming a perfect complete tree, every time we don't find a node we subtract.
		
		//do a dfs on the right side and find missing elements.
		subtraction = findMissing(0, levels, root); 
				
		int totalExpectedNodes = pow(2, levels -1);
		int actualNodes = totalExpectedNodes = subtraction;
		return actualNodes;
		
	}
};


int main(){
	
	Solution s;
    assert(0== s.countNodes(NULL));

	TreeNode *n = new TreeNode(5);
	assert(1 == s.countNodes(n));

	TreeNode *m = new TreeNode(6);
	n -> left = m;
	assert(2 == s.countNodes(n));
	
	TreeNode *o = new TreeNode(7);
	assert(3 == s.countNodes(n));
		
	return 0;
}
