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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        ListNode* curr = head->next;
        head->next = NULL;
        ListNode* nxt;
        while(curr!=NULL)
        {
            nxt = curr->next;
            curr->next = head;
            head = curr;
            curr = nxt;
        }
        
        return head;
    }
};