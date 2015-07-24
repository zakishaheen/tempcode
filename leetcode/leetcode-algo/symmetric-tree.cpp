/*
INCOMPLETE
*/


#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <list>

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
		
		list<TreeNode*> s;
		list<TreeNode*> t;
		
		list<TreeNode *> *currentVector = &s;
		list<TreeNode *> *otherVector = &t;
		
		s.push_back(root);
		
		while(currentVector->size() > 0){
			string output = "";
			
			for(auto i = currentVector->begin(); i!=currentVector->end(); i++){
				currentVector->remove(*i);
			}
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