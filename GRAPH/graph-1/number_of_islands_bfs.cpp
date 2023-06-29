#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid)
{
    visited[row][col]=1;
    queue<pair<int, int>>q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int delrow=-1;delrow<=1;delrow++)
        {
            for(int delcol=-1;delcol<=1;delcol++)
            {
                int nrow=r+delrow;;
                int ncol=c+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol] )
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>visited(n, vector<int>(m, 0));
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && grid[i][j] == '1')
            {
                cnt++;
                bfs(i,j, visited, grid);
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}