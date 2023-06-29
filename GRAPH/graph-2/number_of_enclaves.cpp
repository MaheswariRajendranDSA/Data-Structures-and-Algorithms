#include<bits/stdc++.h>
using namespace std;

void bfs(int n, int m, vector<vector<int>>&vis, vector<vector<int>>&grid)
{
    queue<pair<int, int>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || i==n-1 || j==0 || j==m-1)
            {
            if(!vis[i][j] && grid[i][j]==1)
            {
            q.push({i, j});
            vis[i][j]=1;
            }
            }
        }
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, +1, 0, -1};

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                vis[nrow][ncol]=1;
                q.push({nrow, ncol});
            }
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>grid(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>vis(n, vector<int>(m, 0));
    bfs(n, m, vis, grid);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==0 && grid[i][j]==1)
            {
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}

/*
IP
5 5
0 0 0 1 1
0 0 1 1 0
0 1 0 0 0
0 1 1 0 0
0 0 0 1 1
OP
3
*/