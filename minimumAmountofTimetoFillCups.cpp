class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        pq.push(amount[0]);
        pq.push(amount[1]);
        pq.push(amount[2]);
        int count=0;
        while(true)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a<=0&&b<=0) break;
            a--,b--;
            pq.push(a);
            pq.push(b);
            count++;
        }
        
        return count;
    }
};