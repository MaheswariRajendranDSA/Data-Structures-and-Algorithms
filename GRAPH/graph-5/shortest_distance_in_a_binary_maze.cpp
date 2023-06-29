#include<bits/stdc++.h>
using namespace std;

int shortestPathMaze(int n, int m, vector<vector<int>> &grid, pair<int, int> source, pair<int, int> dest)
{
    if(source.first == dest.first && source.second == dest.second)
    return 0;

    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int> (m, 1e9));
    q.push({0, {source.first, source.second}});
    dist[source.first][source.second]=0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;

        for(int i=0;i<4;i++)
        {
            int newr = row+dr[i];
            int newc = col+dc[i];
            if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc]==1 && dis+1 < dist[newr][newc])
            {
                dist[newr][newc]=dis+1;
                if(newr==dest.first && newc==dest.second)
                return dis+1;
                q.push({dis+1, {newr, newc}});
            }
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    pair<int, int> source, dest;
    cin>>source.first>>source.second;
    cin>>dest.first>>dest.second;
    int res = shortestPathMaze(n, m, grid, source, dest);
    cout<<res<<"\n";
    return 0;
}

/*
IP
5 4
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
0 1
2 2
OP
3
*/