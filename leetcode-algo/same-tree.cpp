#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p!=NULL && q==NULL){ return false;}
        if(p==NULL && q!=NULL){ return false;}
        if(p==NULL && q==NULL){ return true;}
        if(p->val != q->val){ return false;}
        else if(p->val == q->val){
            TreeNode *pl = p->left;
            TreeNode *ql = q->left; 
            
            bool lsame = isSameTree(pl, ql);
            
            TreeNode *pr = p->right;
            TreeNode *qr = q->right;
            
            bool rsame = isSameTree(pr, qr);
            
            return lsame && rsame;
        }
    }
};


int main(int argc, char *argv[]) {
	
	
}