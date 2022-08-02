class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<vector<int>> q;
        q.push({start[0],start[1]});
        vis[start[0]][start[1]]=1;

        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            if(cell[0] == destination[0]&&cell[1] == destination[1])
            return true;
            int i=cell[0];
            int j = cell[1];
            //up
            while(i>=0&&maze[i][j]!=1)
            i--;
            i++;
            if(vis[i][j]==0)
            {
                vis[i][j]=1;
                q.push({i,j});
            }
            //down
            i=cell[0],j=cell[1];
            while(i!=m&&maze[i][j]!=1)
            i++;
            i--;
            if(vis[i][j]==0)
            {
                vis[i][j]=1;
                q.push({i,j});
            }
            //left
            i=cell[0],j=cell[1];
            while(j!=-1&&maze[i][j]!=1)
            j--;
            j++;
            if(vis[i][j]==0)
            {
                vis[i][j]=1;
                q.push({i,j});
            }
            //right
            i=cell[0],j=cell[1];
            while(j!=n&&maze[i][j]!=1)
            j++;
            j--;
            if(vis[i][j]==0)
            {
                vis[i][j]=1;
                q.push({i,j});
            }
        }

        return false;
    }
};