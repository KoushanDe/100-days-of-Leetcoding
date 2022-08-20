class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel>=target) return 0;
        
        int minStop=0;
        int maxDist = startFuel;
        priority_queue<int> pq;
        
        int i=0;
        while(true)
        {   
            if(maxDist>=target) return minStop;
            if(i<stations.size()&&stations[i][0]<=maxDist)
            {
                pq.push(stations[i][1]);
                i++;
            }
            else
            {   
                if(pq.empty())
                    return -1;
                maxDist+=pq.top();
                pq.pop();
                minStop++;
            }
        }
        
        
        return minStop;
    }
};