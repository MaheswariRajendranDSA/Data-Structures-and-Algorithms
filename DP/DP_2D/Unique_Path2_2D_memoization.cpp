#include<bits/stdc++.h>
using namespace std;

int findUniquePathingrid(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp)
{
    if(row>=0&&col>=0&&grid[row][col]==-1)
    return 0;
    if(row==0&&col==0)
    return 1;
    if(row<0||col<0)
    return 0;
    if(dp[row][col]!=-1)
    return dp[row][col];
    int up=findUniquePathingrid(row-1,col, grid, dp);
    int left=findUniquePathingrid(row, col-1, grid, dp);
    return dp[row][col]=up+left;
}
int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>grid(row, vector<int>(col));
    vector<vector<int>>dp(row, vector<int>(col, -1));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<findUniquePathingrid(row-1, col-1, grid, dp);
    return 0;
}
/*
IP
3 3
0 0 0
0 -1 0
0 0 0
OP
2
*/