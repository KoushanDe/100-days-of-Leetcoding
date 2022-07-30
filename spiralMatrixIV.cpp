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
    void buildMatrix(vector<vector<int>>& matrix, int m, int n,ListNode* &root)
    {
        int rowup = m;
        int rowdown = matrix.size()-1-m;
        int colleft = n;
        int colright = matrix[0].size()-1-n; 
        
        for(int j=colleft;j<=colright;j++)
        {
            matrix[rowup][j]=root->val;
            if(root->next==NULL)
                root->next=new ListNode(-1);
            
            root=root->next;
        }
        if(rowup+1>rowdown)
            return;
        for(int i=rowup+1;i<=rowdown;i++)
        {
            matrix[i][colright]=root->val;
            if(root->next==NULL)
                root->next=new ListNode(-1);
                
            root=root->next;
        }
        if(colright-1<colleft)
            return;
        for(int j=colright-1;j>=colleft;j--)
        {
            matrix[rowdown][j]=root->val;
            if(root->next==NULL)
                root->next=new ListNode(-1);
                
            root=root->next;
        }
        if(rowdown-1<=rowup)
            return;
        for(int i=rowdown-1;i>rowup;i--)
        {
            matrix[i][colleft]=root->val;
            if(root->next==NULL)
                root->next=new ListNode(-1);
                
            root=root->next;
        }
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        
        int i=0,j=0;
        
        while(i<(m+1)/2&&j<(n+1)/2)
        {
            buildMatrix(matrix,i,j,head);
            i++,j++;
        }
        
        return matrix;
    }
};