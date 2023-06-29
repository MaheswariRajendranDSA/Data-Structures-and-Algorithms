#include<bits/stdc++.h>
using namespace std;

int findMaximumFallingPath(int i, int j, int row, int col, vector<vector<int>>&matrix, vector<vector<int>>&dp)
{
    if(j<0||j>=col)
    return -1e9;
    if(i==0)
    return dp[0][j]=matrix[0][j];
    if(dp[i][j]!=-1)
    return dp[i][j];
    int down=matrix[i][j]+findMaximumFallingPath(i-1, j, row, col, matrix, dp);
    int leftdiagonal=matrix[i][j]+findMaximumFallingPath(i-1, j-1, row, col, matrix, dp);
    int rightdiagonal=matrix[i][j]+findMaximumFallingPath(i-1, j+1, row, col, matrix, dp);
    return dp[i][j]=max({down, leftdiagonal, rightdiagonal});
}
int main()
{
    int row, col;
    cin>>row>>col;
    int maxi=-1e8;
    vector<vector<int>>matrix(row, vector<int>(col));
    vector<vector<int>>dp(row, vector<int>(col, -1));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<col;i++)
    maxi=max(maxi, findMaximumFallingPath(row-1, i, row-1, col-1, matrix, dp));
    cout<<maxi<<"\n";
    return 0;
}

/*
IP
4 4
1 2 10 4
100 3 2 1
2 1 20 2
1 2 2 1
OP
106
*/