#include<bits/stdc++.h>
using namespace std;

int find_rotten_orange(int n, int m, vector<vector<int>>&grid)
{
    queue<pair<pair<int, int>, int>>q;
    int vis[n][m];
    int cntfresh=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i, j}, 0});
                vis[i][j]=2;
            }
            else 
            {
            vis[i][j] = 0;
            }
            if(grid[i][j]==1)
            cntfresh++;
        }
    }

    int time=0, cnt=0;
    int delrow[]={-1, 0, 1, 0};
    int delcol[]={0, 1, 0, -1};
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        time=max(t, time);
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
            {
                vis[nrow][ncol]=2;
                cnt++;
                q.push({{nrow, ncol}, t+1});
            }
        }
    }
        if(cnt==cntfresh)
        return time;
        else
        return -1;
    
}
int main(){
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
        int res=find_rotten_orange(n, m, grid);
        cout<<res<<"\n";
        return 0;
    }
}

/*
IP
3 3
0 1 2
0 1 2
2 1 1
OP
1
*/