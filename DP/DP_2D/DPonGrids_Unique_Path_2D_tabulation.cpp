#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>dp(row, vector<int>(col, 0));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0&&j==0)
            {
            dp[i][j]=1;
            continue;
            }
            int up=0;
            int left=0;
            if(i>0)
            up=dp[i-1][j];
            if(j>0)
            left=dp[i][j-1];
            dp[i][j]=up+left;
        }
    }
    cout<<dp[row-1][col-1];
    return 0;
}
/*
IP
3 2
OP
3
*/