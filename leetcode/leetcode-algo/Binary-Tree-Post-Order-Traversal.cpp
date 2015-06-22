/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <vector> 
 using namespace std;
 
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		
		if(!root) return vector<int>();
		
		vector<int> left = postorderTraversal(root->left);
		vector<int> right = postorderTraversal(root->right);
		
		result.insert(result.end(), left.begin(), left.end());
		result.insert(result.end(), right.begin(), right.end());
		result.push_back(root->val);
		
		return result;
	}
};