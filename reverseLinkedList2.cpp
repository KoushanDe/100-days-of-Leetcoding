/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        
        ListNode* leftNode=head;
        ListNode* prevNode=NULL;
        ListNode* rightNode=head;
        ListNode* nxtNode=NULL;
        
        
        while(left>1)
        {   
            prevNode=leftNode;
            leftNode=leftNode->next;
            left--;
        }
        while(right>1)
        {
            rightNode=rightNode->next;
            nxtNode=rightNode->next;
            right--;
        }
        
        ListNode* prev = nxtNode;
        ListNode* nxt;
        
        while(leftNode!=nxtNode)
        {   
            nxt = leftNode->next;
            leftNode->next = prev;
            prev = leftNode;
            leftNode = nxt;
        }
    
        if(prevNode==NULL)
            return rightNode;
        else
        {   
            prevNode->next=rightNode;
            return head;
        }
            
    }
};