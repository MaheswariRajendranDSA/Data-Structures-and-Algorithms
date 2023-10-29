#include<bits/stdc++.h>
using namespace std;

void Solve(int i, int j, vector<vector<int>>&m, int n, vector<string>&ans, string move, vector<vector<int>>&vis)
{
    if(i==n-1&&j==n-1)
    {
        ans.push_back(move);
        return;
    }
    //down
    if(i+1<n&&!vis[i+1][j]&&m[i+1][j]==1)
    {
        vis[i][j]=1;
        Solve(i+1, j, m, n, ans, move+'D', vis);
        vis[i][j]=0;
    }
    //left
    if(j-1>=0&&!vis[i][j-1]&&m[i][j-1]==1)
    {
        vis[i][j]=1;
        Solve(i, j-1, m, n, ans, move+'L', vis);
        vis[i][j]=0;
    }
    //right
    if(j+1<n&&!vis[i][j+1]&&m[i][j+1]==1)
    {
        vis[i][j]=1;
        Solve(i, j+1, m, n, ans, move+'R', vis);
        vis[i][j]=0;
    }
    //upward
    if(i-1>=0&&!vis[i-1][j]&&m[i-1][j]==1)
    {
        vis[i][j]=1;
        Solve(i-1, j, m, n, ans, move+'U', vis);
        vis[i][j]=0;
    }
}
vector<string>findPath(vector<vector<int>>&m, int n)
{
    vector<string>ans;
    vector<vector<int>> vis(n, vector<int>(n,0));
    if(m[0][0]==1)
    {
        Solve(0,0,m,n,ans, " ", vis);
        return ans;
    }

}
int main()
{
    int n=4;
    vector<vector<int>>m{
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string>result;
    result=findPath(m, n);
    if(result.size()==0)
    cout<<-1;
    else
    for(int i=0;i<result.size();i++)
    cout<<result[i]<<"\n";
    return 0;
}
/*
OP
 DDRDRR
 DRDDRR*/