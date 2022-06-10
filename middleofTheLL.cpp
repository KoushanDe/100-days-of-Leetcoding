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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)return head;
        int len=0;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            curr=curr->next;
            len++;
        }
        
        len/=2;
        
        while(len>0)
        {
            head=head->next;
            len--;
        }
        return head;
    }
};