#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <cassert>
#include <algorithm>

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

	TreeNode *buildTreeR(vector<int> &inorder, vector<int> &postorder, vector<int>::iterator inorderbegin, vector<int>::iterator inorderend, vector<int>::iterator postorderbegin, vector<int>::iterator postorderend){

		
		if(inorderbegin == inorderend){

			TreeNode *head = new TreeNode(*inorderbegin);
			head->left = NULL;
			head->right = NULL;
			
			return head;
		}else{

			
			int key = *postorderend;
			TreeNode *head = new TreeNode(key);
			head->left = NULL;
			head->right = NULL;
			
			auto inorderkeyit = find(inorderbegin, inorderend, key);
			auto leftinorderbegin = inorderbegin;
			auto leftinorderend = inorderkeyit - 1;
			vector<int>::iterator leftpostorderbegin = postorder.end();
			vector<int>::iterator leftpostorderend = postorder.end();
			int leftsize = distance(leftinorderbegin, leftinorderend);

			if(leftinorderbegin == inorderkeyit){
				head-> left = NULL; //first element hence no other on the left side. 
				leftsize = 0;
			}
			else{
				leftpostorderbegin = postorderbegin;
				leftpostorderend = postorderbegin + leftsize;
				
				head->left = buildTreeR(inorder, postorder, leftinorderbegin, leftinorderend, leftpostorderbegin, leftpostorderend);
			}
			
			
			auto rightinorderbegin = inorderkeyit + 1;
			auto rightinorderend = inorderend;
			
			vector<int>::iterator rightpostorderbegin;
			vector<int>::iterator rightpostorderend;
			
			int rightsize = distance(rightinorderbegin, rightinorderend)+1;
			
			if(rightinorderend == inorderkeyit){
				rightsize = 0;
				//last element so no more elements on the right size
				head->right = NULL;
			}
			else{
				if(leftpostorderend == postorder.end()){
					//there is no left size. 
					rightpostorderbegin = postorderbegin;
				}else{
					rightpostorderbegin = leftpostorderend + 1;

				}
				
				rightpostorderend = postorderend - 1;				
				head->right = buildTreeR(inorder, postorder, rightinorderbegin, rightinorderend, rightpostorderbegin, rightpostorderend);
			}
			
			
			return head; 
		}
	}
	
	
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	
		if(postorder.size()==0) return NULL;
		
		return buildTreeR(inorder, postorder, inorder.begin(), inorder.end() - 1, postorder.begin(), postorder.end() - 1);
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
	
//	inorder.push_back(1);
//	inorder.push_back(2);
//	inorder.push_back(3);
//	inorder.push_back(4);
//	
//	postorder.push_back(3);
//	postorder.push_back(2);
//	postorder.push_back(4);
//	postorder.push_back(1);
//		
//	TreeNode * x = s.buildTree(inorder, postorder);
//	assert(x!=NULL);
//	print(x); cout<<endl;
	
	
	
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