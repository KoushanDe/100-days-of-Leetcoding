#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* curr = head;
        Node * nex;
        
        //creating deepcopy nodes next to original nodes
        while(curr!=NULL)
        {
            nex = curr->next;
            
            curr->next = new Node(curr->val);
            
            curr->next->next = nex;
            
            curr = nex;
        }
        
        curr=head;
        
        //assigning correct random pointers of deepcopy nodes
        while(curr!=NULL)
        {
            if(curr->random)curr->next->random = curr->random->next;
            else curr->next->random=NULL;
            curr = curr->next->next;
        }
        
        Node* ans = head->next;
        
        //seperating original and duplicate LL
        curr = head;
        nex = head->next;
        
        while(curr!=NULL)
        {
            curr->next = curr->next->next;
            curr = curr->next;
            nex->next = nex->next?nex->next->next:NULL;
            nex = nex->next;
        }
        
        return ans;
    }
};