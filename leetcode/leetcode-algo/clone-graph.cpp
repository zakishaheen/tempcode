#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
	
	
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node==NULL) return NULL;
		
		UndirectedGraphNode *result;
		
		stack<UndirectedGraphNode *> S;
		stack<UndirectedGraphNode *> S2;
		
		map<UndirectedGraphNode *, int> visited;
		
		UndirectedGraphNode *newRoot = new UndirectedGraphNode(node->label);
		S2.push(newRoot);
		S.push(node);
		
		result = newRoot;
		while(!S.empty()){
			UndirectedGraphNode * T = S.top();
			UndirectedGraphNode * T2 = S2.top();
			
			S2.pop();
			S.pop();
			
			for(auto it =(T->neighbors).begin(); it != (T->neighbors).end(); it++){
				if(visited.find(*it)==visited.end()){
					UndirectedGraphNode *nn = new UndirectedGraphNode((*it)->label);
					(T2->neighbors).push_back(nn);
					S2.push(nn);
					S.push(*it);
				}else{
					UndirectedGraphNode *nn = new UndirectedGraphNode((*it)->label);
					(T2->neighbors).push_back(nn);
				}
			}
			
			visited[T] = true;
		}
		
		return result;
		
	}
};

int main(int argc, char *argv[]) {
	
}