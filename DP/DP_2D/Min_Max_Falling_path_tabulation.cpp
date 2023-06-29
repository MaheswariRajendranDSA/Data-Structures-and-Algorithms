#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>matrix(row, vector<int>(col));
    vector<vector<int>>dp(row, vector<int>(col, 0));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }
    for(int j=0;j<col;j++)
    dp[0][j]=matrix[0][j];

    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int down=matrix[i][j]+dp[i-1][j];
            int leftdiagonal=matrix[i][j];
            if(j-1>=0)
            leftdiagonal+=dp[i-1][j-1];
            int rightdiagonal=matrix[i][j];
            if(j+1<=col-1)
            rightdiagonal+=dp[i-1][j+1];
            dp[i][j]=max({down, leftdiagonal, rightdiagonal});
        }
    }
    int maxi=dp[row-1][0];
    for(int i=1;i<col;i++)
    maxi=max(maxi, dp[row-1][i]);
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