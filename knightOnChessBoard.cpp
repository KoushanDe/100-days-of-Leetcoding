int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> matdis(A,vector<int>(B,-1));
    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};
    
    matdis[C-1][D-1] = 0;
    queue<pair<int,int>> q;
    q.push({C-1,D-1});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int dist = matdis[x][y];
        q.pop();
        
        if(x==E-1&&y==F-1)
        return dist;
        
        for(int i=0;i<8;i++)
        {
            int newx = x+dx[i];
            int newy = y+dy[i];
            
            if(newx>=0&&newx<A&&newy>=0&&newy<B&&matdis[newx][newy]==-1)
            {
                matdis[newx][newy]=dist+1;
                q.push({newx,newy});
            }
        }
    }
    
    return -1;
}
