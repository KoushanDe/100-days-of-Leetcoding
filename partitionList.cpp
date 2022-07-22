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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        
        ListNode* leftNode=NULL;
        ListNode* rightNode=NULL;
        ListNode* leftHead=NULL;
        ListNode* rightHead=NULL;
        
        while(head)
        {
            if(head->val<x)
            {
                if(leftNode==NULL)
                {
                    leftNode=head;
                    leftHead=leftNode;
                }
                else
                {
                    leftNode->next=head;
                    leftNode=leftNode->next;
                }
            }
            else
            {
                if(rightNode==NULL)
                {
                    rightNode=head;
                    rightHead=rightNode;
                }
                else
                {
                    rightNode->next=head;
                    rightNode=rightNode->next;
                }
            }
            
            head=head->next;
        }
        
        if(leftNode)leftNode->next = rightHead;
        if(rightNode)rightNode->next = NULL;
        
        return leftHead==NULL?rightHead:leftHead;
    }
};