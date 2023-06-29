#include<bits/stdc++.h>
using namespace std;

int findMinPathSum(int i, int j, int row, vector<vector<int>>&triangle, vector<vector<int>>&dp)
{
    if(i==row)
    return dp[i][j]=triangle[i][j];
    if(dp[i][i]!=-1)
    return dp[i][j];
    int down=findMinPathSum(i+1, j, row, triangle, dp)+triangle[i][j];
    int diagonal=findMinPathSum(i+1, j+1, row, triangle, dp)+triangle[i][j];
    return dp[i][j]=min(down, diagonal);
    
}
int main()
{
    int row;
    cin>>row;
    vector<vector<int>>triangle(row, vector<int>(row));
    vector<vector<int>>dp(row, vector<int>(row, -1));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=i;j++)
         cin>>triangle[i][j];
    }
    cout<<findMinPathSum(0, 0, row-1, triangle, dp);
    return 0;
}
/*
IP
4
1
2 3
3 6 7
8 9 6 10
OP
14
*/