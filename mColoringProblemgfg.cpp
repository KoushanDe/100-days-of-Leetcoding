// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isValid(bool graph[101][101],int v,int colour, vector<int>& col)
{
    for(int j=0;j<col.size();j++)
    {
        if(j!=v&&graph[v][j]==true)
        {
            if(colour==col[j])
            return false;
        }
    }
    return true;
}
bool canColour(bool graph[101][101], int m, int v, vector<int>& col)
{
    if(v == col.size())
    return true;
    
    for(int i=1;i<=m;i++)
    {
        if(isValid(graph,v,i,col)==true)
        {
            col[v]=i;
            if(canColour(graph,m,v+1,col)==true)
            return true;
            else
            col[v]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colour(V,0);
    return canColour(graph,m,0,colour);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends