#include <iostream>

using namespace std;

/*
Question: https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/
/**
 * Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 */

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:

void connect(TreeLinkNode *root) {
	if(!root) return;
	else if(!(root->left && root->right)) return;
	else{
		connect(root->left);
		connect(root->right);
		
		TreeLinkNode *righters = root->left;
		TreeLinkNode *lefters = root->right;
		
		
		while(righters!=NULL && lefters!=NULL){
			righters->next = lefters;
			
			righters = righters->right;
			lefters = lefters->left; 
		}
		
	}
}
};
void print(TreeLinkNode *n){
	if(n==NULL) return;
	else{
		print(n->left);
		cout<<n->val<<",";
		print(n->right);
		cout<<endl;
	}
}

int main(int argc, char *argv[]) {
	Solution s;
	
	TreeLinkNode *r1 = new TreeLinkNode(0);
//	s.connect(r1);
//	print(r1);
	
	TreeLinkNode *r2 = new TreeLinkNode(1);
	TreeLinkNode *r3 = new TreeLinkNode(2);
	
	r1->left = r2;
	r1->right = r3;
	
	s.connect(r1);
	print(r1);
}