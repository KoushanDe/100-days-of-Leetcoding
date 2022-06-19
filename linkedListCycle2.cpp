#include<bits/stdc++.h>
using namespace std;

 Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL||head->next==NULL)return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        do{
            slow= slow->next;
            fast = fast->next->next;
        }while(slow!=fast&&fast&&fast->next);
        
        if(fast==NULL||fast->next==NULL)return NULL;
        
        slow = head;
        
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};