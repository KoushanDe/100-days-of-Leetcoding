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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1||head==NULL) return head;
        
        int count=0;
        
        ListNode* cur = head;
        
        while(cur!=NULL)
        {
            count++;
            cur=cur->next;
        }
        
        ListNode* dummy = new ListNode();
        cur = head;
        ListNode* nex = cur->next;
        ListNode* pre = dummy;
        pre->next=cur;
        
        while(count>=k)
        {
            for(int i=1;i<k;i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            
            count -= k;
            pre = cur;
            cur = pre->next;
            if(cur!=NULL)nex = cur->next;
        }
        
        return dummy->next;
    }
};