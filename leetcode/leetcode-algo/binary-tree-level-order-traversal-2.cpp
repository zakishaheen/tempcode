#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
	
class Solution {
		public:
			vector<vector<int> > levelOrderBottom(TreeNode *root) {
				
					//for each node N at level i, add N.left and N.right to level i+1
					//while level i is empty
					
					//finally traverse and create the numbers list. 
					
				int currentLevel = 0;
				
				if(root==NULL){
					vector< vector<int> > result(0);
					return result;
				} 
				vector< vector<int> > result(1);
				
				vector< vector<TreeNode*> > levels(1);
				
				levels[currentLevel].push_back(root);

				while(true){
					vector<TreeNode *> currentLevelVector = levels[currentLevel];
					
					if(currentLevelVector.size()==0) break;
					
					for(int i=0;i<currentLevelVector.size();i++){
						TreeNode *n = currentLevelVector[i];
						
						if(levels.size()-1 == currentLevel){
							levels.push_back(vector<TreeNode*>());
						}
						if(n->left) levels[currentLevel+1].push_back(n -> left);
						if(n->right) levels[currentLevel+1].push_back(n -> right);
					}			
					
					currentLevel++;
					
				}
				
				for(int i=0;i<levels.size(); i++){
					
					vector<TreeNode*> n = levels[i];
					
					if(i>0 && n.size()>0) result.push_back(vector<int>(0));
					
					for(int j=0;j<n.size(); j++){
						int value = n[j]->val;
						result[i].push_back(value);
					}
				}
				
				reverse(result.begin(), result.end());
				return result;
			}
		};


void printResult(vector<vector<int> > result){
	
	cout<<"result size = "<<result.size()<<endl;
	
	for(int i=0;i<result.size(); i++){
		vector<int> v = result[i];
		
		cout<<"i size = "<<v.size()<<endl;
		for(int j=0;j< v.size(); j++){
			cout<<v[j]<<",";
		}
		cout<<endl;
	}
}
void testEmpty(){
	Solution s;
	vector<vector<int> > result;
	
	result = s.levelOrderBottom(NULL);
	printResult(result);
	
}

void testOne(){
	Solution s;
	TreeNode *n = new TreeNode(0);
	n->left =NULL;
	n->right = NULL;
	
	vector<vector<int> > result;
	
	result = s.levelOrderBottom(n);
	printResult(result);
	
}


void testTwo(){
	Solution s;
	TreeNode *n = new TreeNode(0);
	
	n->left = new TreeNode(1);
	n->right = new TreeNode(2);
	
	n->left->left = new TreeNode(4);

	vector<vector<int> > result;
	
	result = s.levelOrderBottom(n);
	
	printResult(result);
	
}



int main(int argc, char *argv[]) {
	//testEmpty();
	//testOne();	
	testTwo();
}