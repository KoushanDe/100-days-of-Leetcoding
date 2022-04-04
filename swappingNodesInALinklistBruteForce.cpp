#include<bits/stdc++.h>
#include<iostream>

using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> elem;
        ListNode* dummy = head;
        while(dummy!=NULL)
        {
            elem.push_back(dummy->val);
            dummy = dummy->next;
        }
        
        dummy = head;
        
        swap(elem[k-1],elem[elem.size()-k]);
        int i=0;
        while(dummy!=NULL)
        {
            dummy->val = elem[i];
            dummy = dummy->next;
            i++;
        }
        return head;
    }
};