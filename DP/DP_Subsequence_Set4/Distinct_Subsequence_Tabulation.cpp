#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    
    vector<vector<int>>dp(strlen+1, vector<int>(tarlen+1, 0));

    for(int i=0;i<=strlen;i++)
    dp[i][0]=1;
    for(int j=1;j<=tarlen;j++)
    dp[0][j]=0;

    for(int i=1;i<=strlen;i++)
    {
        for(int j=1;j<=tarlen;j++)
        {
            if(str[i-1]==tar[j-1])
            {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else
            {
            dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[strlen][tarlen]<<"\n";
    return 0;
}

/*
IP
babgbag
bag
OP
5
*/