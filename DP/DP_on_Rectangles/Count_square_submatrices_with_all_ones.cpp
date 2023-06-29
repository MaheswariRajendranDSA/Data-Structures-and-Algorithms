#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>mat[i][j];
    }
    vector<vector<int>>dp(n, vector<int>(m, 0));
    for(int j=0;j<m;j++)
    dp[0][j]=mat[0][j];
    for(int i=0;i<n;i++)
    dp[i][0]=mat[i][0];

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j]==0)
            dp[i][j]=0;
            else
            {
                dp[i][j]=1+min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]});
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sum+=dp[i][j];
        }
    }
    cout<<sum<<"\n";
    return 0;
}

/*
IP
3 4
0 1 1 1 
1 1 1 1 
0 1 1 1
OP
15
*/