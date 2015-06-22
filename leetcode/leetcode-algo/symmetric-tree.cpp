/*
INCOMPLETE
*/


#include <string>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

using namespace std;

class Solution {
public:
	
	
	
	bool isSymmetric(TreeNode* root) {
		//build level order.
		int currentLevel = 0;
		
		vector< vector<TreeNode *> > levels;
		
		vector<TreeNode *> rootLevel(1);
		rootLevel.push_back(root);
		
		levels.push_back(rootLevel);
		
		while(tree){
			auto x = levels[currentLevel];
			
			for(auto i = x.begin(); i!=x.end(); i++){
				auto nextVector = levels[currentLevel+1];
				nextVector.push_back((*x)->left);
				nextVector.push_back((*x)->right);
			}
			
			currentLevel++;
			
			
		}
		
		// check if each level is palindrome. 
	}
};


int main(){
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(3);
	TreeNode *e = new TreeNode(2);
	
	a->left = b;
	a->right = c;
	b->left = d;
	c->left = e;
	
	Solution s;
	assert(false == s.isSymmetric(a));
	
	
	return 0;
}