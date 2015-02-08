#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>

using namespace std;

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root==NULL) return 0;
        
        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        
        if(left>right){
            return left;
        }else{
            return right;
        }
    }
};

int main(int argc, char *argv[]) {
	
}