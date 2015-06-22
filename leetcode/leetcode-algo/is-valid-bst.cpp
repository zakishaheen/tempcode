/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if(!root) return true;
		if(!(root->left) && !(root->right)) return true;
		
		if(root->left && root->left->val >= root->val) return false;
		if(root->right && root->right->val <= root->val) return false;

		TreeNode* gl = root->left;
		while(gl && gl->right!=NULL){ gl = gl->right; }
		if(gl && gl->val >= root->val){ return false; }

		TreeNode *lr = root->right;
		while(lr && lr->left!=NULL){ lr = lr->left;}
		if(lr && lr->val <= root->val){ return false; }
		
		return isValidBST(root->left) && isValidBST(root->right);
	}
};