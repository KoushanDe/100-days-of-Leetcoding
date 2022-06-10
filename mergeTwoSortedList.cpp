
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
   ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        
        ListNode* list3;
        ListNode* curr=new ListNode();
        
        list3=curr;
        
        while(list1!=NULL&&list2!=NULL)
        {
            if(list1->val<list2->val)
            {   
                curr->next=list1;
                //cout<<curr->val<<"first";
                list1 = list1->next;
            }
            else
            {
                curr->next=list2;
                //cout<<curr->val<<"second";
                list2 = list2->next;
            }
            
                curr=curr->next;
        }
        
        while(list1!=NULL)
        {
            curr->next=list1;
            curr=curr->next;
            //cout<<curr->val<<"third";
            list1=list1->next;
        }
        while(list2!=NULL)
        {
            curr->next=list2;
            curr=curr->next;
            //cout<<curr->val<<"last";
            list2=list2->next;
        }
        
        return list3->next;
    }
};