#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    typedef vector<int> pd; 
    struct myComp { 
       bool operator() (const pd &p1, const pd &p2) {
          return p1[0] > p2[0];
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        
        priority_queue<pd, vector<pd>, myComp> pq;
        int path[] = {0, 1, 0, -1, 0};
        pq.push({0,0,0});
        
        while(!pq.empty()) {
            int effort = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            
            if(i == n-1 && j == m-1){
                return effort;
            }
            
            for(int k = 0; k < 4; k++) {
                int r = i + path[k], c = j + path[k+1];
                if(r >= 0 && r < n && c >= 0 && c < m) {
                    int next = max(effort, abs(heights[i][j] - heights[r][c]));
                    if(efforts[r][c] > next) {
                        efforts[r][c] = next;
                        pq.push({next,r,c});
                    }
                }
            }
        }
        
        return -1;
    }
};