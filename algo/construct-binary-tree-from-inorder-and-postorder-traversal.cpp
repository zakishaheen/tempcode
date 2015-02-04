#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <cassert>

using namespace std;

/**
 * Definition for binary tree

 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	
		
		if(inorder.size()==0) return NULL;
		
		int X = postorder[postorder.size()-1];
		
		
		TreeNode *head = new TreeNode(X);
		
		for(int i=0;i<inorder.size();i++){
			if(inorder[i]==X){
				vector<int> leftinorder; 
				vector<int> rightinorder; 
				vector<int> leftpostorder;
				vector<int> rightpostorder;
								
				for(int j = 0;	j < i;j++){ leftinorder.push_back(inorder[j]); }
				for(int j = i+1;j < inorder.size();j++){ rightinorder.push_back(inorder[j]); }
				
				int r = postorder.size() - 1;
				for(int i=0;i<rightinorder.size();i++){
					rightpostorder.push_back(postorder[--r]);
				}
				
				for(int i=0;i<leftinorder.size();i++){
					leftpostorder.push_back(postorder[--r]);
				}
				
				TreeNode *left = buildTree(leftinorder, leftpostorder);
				TreeNode *right = buildTree(rightinorder, rightpostorder);
				
				head->left = left;
				head->right = right;
				
				return head;
				
			}
		}
		return NULL;
    }
};


void print(TreeNode *n){
	if(n==NULL) return;
	else{
		print(n->left);
		cout<<n->val<<",";
		print(n->right);
	}
}

int main(int argc, char *argv[]) {
	vector<int> inorder;
	vector<int> postorder;
	
	Solution s;
	TreeNode * n = s.buildTree(inorder, postorder);
	assert(n==NULL);
	
	inorder.push_back(1);
	postorder.push_back(1);
	TreeNode * x = s.buildTree(inorder, postorder);
	assert(x!=NULL);
	print(x); cout<<endl;
	
	
	inorder.clear();
	postorder.clear();
	
	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	inorder.push_back(5);
	inorder.push_back(6);
	inorder.push_back(7);
	inorder.push_back(8);
	inorder.push_back(9);
	
	postorder.push_back(1);
	postorder.push_back(3);
	postorder.push_back(5);
	postorder.push_back(4);
	postorder.push_back(2);
	postorder.push_back(8);
	postorder.push_back(9);
	postorder.push_back(7);
	postorder.push_back(6);
	
	
	TreeNode *R = s.buildTree(inorder, postorder);
	
	print(R);
		
}