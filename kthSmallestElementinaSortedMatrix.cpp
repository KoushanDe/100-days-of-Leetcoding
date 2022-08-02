class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxheap;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                maxheap.push(matrix[i][j]);
                if(maxheap.size()>k)
                    maxheap.pop();
            }
        }
        
        return maxheap.top();
    }
};