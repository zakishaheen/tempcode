#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        if(head->next==NULL) return false;
        if(head->next->next==NULL) return false;
        
        ListNode *slowRunner = head;
        ListNode *fastRunner = head;
        
        do{
            if(fastRunner->next==NULL || fastRunner->next->next==NULL) return false;
            if(slowRunner->next==NULL) return false; 
            
            fastRunner = fastRunner->next->next;
            slowRunner = slowRunner->next;
        }while(fastRunner!=NULL && slowRunner!=NULL && fastRunner!=slowRunner);
        
        if(fastRunner!=NULL && slowRunner!=NULL){
            return true;
        }else{
            return false;
        }
        
    }
};

int main(int argc, char *argv[]) {
	//not possible to write a terese test code
}