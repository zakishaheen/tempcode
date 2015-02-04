#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <cassert>

using namespace std;


/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTreeR(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd){
//		cout<<"preStart="<<preStart<<" preEnd="<<preEnd<<endl;
		
        TreeNode *result = NULL;

		if(preEnd<preStart){
			result = NULL;
		}
        else if(preStart==preEnd){
			int x = preorder[preStart];
//			cout<<"creating node: "<<x<<endl;
			TreeNode *head = new TreeNode(x);
            result =  head;
        }
        
		else{
			
            int interest = preorder[preStart];
			cout<<"finding"<<interest<<endl;
            
			cout<<"[";
			for(int i=inStart; i<=inEnd; i++){
				
				cout<<inorder[i]<<",";
			}
			cout<<"]"<<endl;;
			
			for(int i=inStart; i<=inEnd; i++){
				
				
                if(inorder[i]==interest){
                    cout<<"found "<<interest<<". ";

                    TreeNode *head = new TreeNode(preorder[interest]);
					cout<<endl<<"[";
					for(int k=inStart; k<=i-1; k++){
				
						cout<<inorder[k]<<",";
					}cout<<"]";

					cout<<"[";
					for(int k=i+1; k<=inEnd; k++){
				
						cout<<inorder[k]<<",";
					}cout<<"]"<<endl;



					cout<<endl<<"[";

				int leftSize = i - inStart;
				for(int k=preStart+1; k<=leftSize; k++){
				
						cout<<preorder[k]<<",";
					}cout<<"]";

					cout<<"[";
					for(int k=leftSize+1; k<=preEnd; k++){
				
						cout<<preorder[k]<<",";
					}cout<<"]"<<endl;

					cout<<"=======START of left for "<<interest<<endl;					
					
                    head->left = buildTreeR(preorder, inorder, preStart + 1, leftSize, inStart, i-1);
					cout<<"=======END of left for "<<interest<<endl;
					cout<<"=======Start of right for "<<interest<<endl;
                    head->right = buildTreeR(preorder, inorder, leftSize + 1, preEnd, i+1, inEnd);
                    					cout<<"=======END of right for "<<interest<<endl;
                    result = head;
                    break;
                }
            }
			cout<<endl;
        }
        return result; 
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeR(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
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
	vector<int> preorder;
	
	Solution s;
	
	
	inorder.clear();
	preorder.clear();
	
	
	preorder.push_back(6);
	preorder.push_back(5);
	preorder.push_back(1);
	preorder.push_back(4);
	preorder.push_back(2);
	preorder.push_back(3);
	preorder.push_back(9);
	preorder.push_back(8);
	preorder.push_back(7);
	
	
	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	inorder.push_back(5);
	inorder.push_back(6);
	inorder.push_back(7);
	inorder.push_back(8);
	inorder.push_back(9);
	
	
	TreeNode *R = s.buildTree(preorder, inorder);
	
	print(R);
		
}