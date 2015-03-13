#include <iostream>

using namespace std;
/*
Given a binary tree, return the inorder traversal of its nodes' values.


*/
class Solution {
	public:
		void traverse(TreeNode *node, vector<int>* solution){
			if(node==NULL) return;
			traverse(node->left, solution);
			solution->push_back(node->val);
			traverse(node->right, solution);
		}
		
		
		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> *result = new vector<int>();
			
			traverse(root, result);
			
			return *result;
		}
	};
	
	
int main(int argc, char *argv[]) {
	
}