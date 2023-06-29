#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>&visited, vector<vector<int>>&grid, 
vector<pair<int, int>>&islands, int baseRow, int baseCol)
{
    visited[row][col]=1;
    int n = grid.size();
    int m = grid[0].size();
    islands.push_back({row-baseRow, col-baseCol});

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0,+1};

    for(int i=0;i<4;i++)
    {
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]&& grid[nrow][ncol]==1)
        {
            dfs(nrow, ncol, visited, grid, islands, baseRow, baseCol);
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
    vector<vector<int>>visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && grid[i][j]==1)
            {
                vector<pair<int, int>> islands;
                dfs(i, j, visited, grid, islands, i, j);
                st.insert(islands);
            }
        }
    }
    cout<<st.size();
    return 0;
}

/*
IP
4 5
1 1 0 1 1
1 0 0 0 0
0 0 0 1 1
1 1 0 1 0
OP
2
*/