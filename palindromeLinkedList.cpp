#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow;
        ListNode* fast;
        slow=head;
        fast=head;
        
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* nex = head->next;
        
        
        while(curr!=slow)
        {
            curr->next = pre;
            pre = curr;
            curr = nex;
            nex = nex->next;
        }
        
        if(fast!=NULL)slow=slow->next;
        while(slow!=NULL)
        {
            if(slow->val!=pre->val)
                return false;
            pre = pre->next;
            slow=slow->next;
        }
        return true;
        
    }
};