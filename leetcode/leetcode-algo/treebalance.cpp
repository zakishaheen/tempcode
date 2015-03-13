#include <iostream>
#include <deque>

using namespace std;


struct Node{
	Node *left;
	Node *right;
	int val;
};



bool isBalanced(Node *tree){
	bool result = false;
	
	if(tree==NULL){ result = true; } 
	else if(tree.left==NULL && tree.right==NULL){ return true; }
	else if(tree.left==NULL && tree.right!=NULL){ return false; }
	else if(tree.left!=NULL && tree.right==NNUL){ return false; }
	else{
		bool left = isBalanced(tree->left);
		bool right = isBalanced(tree->right);
		
		result = left && right;
	}
	
	return result;
}


/*
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.Constraints:
all nodes connected?
Do we have a graph or a forest?
Is there a particular datastructure to follow?
Do we take care of loops? 
Do we take care of weights?
What is the output that is needed? The path forward or backward - or simply yes/no?

Assumptions:

Ideas:
BFS from starting node.
DFS from starting node. 


Tests:
Code:



*/

bool pathExists(Node *start, Node *end){
	vector<Node> visitedList; 
	
	deque<Node> Q;
	Q.push_back(start);
	
	while(Q.is_empty()!=true){
		Node *t = q.pop();
		
		if(visitedList.contains(t)){continue;}
		
		for(Node *n : t.children){
			Q.push_back(n);
		}
		
		if(t.val == end.val) {return true; }
		
		else{
			visitedList.push_back(t);
			
		}
	}
	return false;
}



/*
Given a sorted (increasing order) array with unique integer elements, write an algo- rithm to create a binary search tree with minimal height.Constraints
unique integer elements. 
minimal height tree > make it balanced. 

Ideas
travese in a binary search method, keep reference of node being added and add nodes. 
can make it recursive - edge case is when there is no more children to be added. 

T

Code



*/

Node * createBST(int[] array, int start, int length){
	//find center
	if(length==0){return NULL;}
	
	int center = length/2; 
	Node *left = createBST(array, 0, center-1);
	Node *right = createBST(array, center+1, length);
	
	Node *c = new Node;
	c.val = center;
	c.left = left;
	c.right= right;
	return c; 
}


/*
Given a binary tree, design an algorithm which creates a linked list of all the nodes at
each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

Constraints
Ideas
Tests
Code

array of linkedlist - 

*/

createLinkedList(Node *head, int depth){

	appendChildrenToList(head.left, list);	
	appendChildrenToList(head.right, list);	
}

int main(int argc, char *argv[]) {
	
}