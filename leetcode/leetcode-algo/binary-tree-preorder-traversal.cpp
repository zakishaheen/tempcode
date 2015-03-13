#include <iostream>

using namespace std;
/*
Given a binary tree, return the inorder traversal of its nodes' values.


*/
class Solution {
	public:
		void traverse(TreeNode *node, vector<int>* solution){
			if(node==NULL) return;
			solution->push_back(node->val);
			traverse(node->left, solution);
			traverse(node->right, solution);
			
		}
		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> *result = new vector<int>();
			
			traverse(root, result);
			
			return *result;
		}
	};
	
	
int main(int argc, char *argv[]) {
	
}