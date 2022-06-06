#include<bits/stdc++.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,bool> isNode;
        
        while(headA!=NULL)
        {
            isNode[headA] = true;
            headA = headA->next;
        }
        while(headB!=NULL)
        {
            if(isNode[headB]==true)
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};