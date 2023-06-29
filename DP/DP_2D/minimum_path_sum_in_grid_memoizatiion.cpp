#include<bits/stdc++.h>
using namespace std;

int findMinimumPathSum(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp)
{
    if(row==0&&col==0)
    return dp[row][col]=grid[0][0];
    if(row<0||col<0)
    return 1e9;
    if(dp[row][col]!=-1)
    return dp[row][col];
    int up=findMinimumPathSum(row-1, col, grid, dp)+grid[row][col];
    int left=findMinimumPathSum(row, col-1, grid, dp)+grid[row][col];
    return dp[row][col]=min(up, left);
}
int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>grid(row, vector<int>(col));
    vector<vector<int>>dp(row, vector<int>(col,-1));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        cin>>grid[i][j];
    }
    cout<<findMinimumPathSum(row-1, col-1, grid, dp);
    return 0;
}
/*
IP
2 3           
5 9 6
11 5 2
OP
21
*/