
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len=0;
        
        while(curr!=NULL)
        {
            curr=curr->next;
            len++;
        }
        
        len-=n;
        if(len==0)return head->next;
        curr=head;
        while(true)
        {
            if(len==1)
            {
                curr->next = curr->next->next;
                break;
            }
            curr=curr->next;
            len--;
        }
        return head;
    }
};