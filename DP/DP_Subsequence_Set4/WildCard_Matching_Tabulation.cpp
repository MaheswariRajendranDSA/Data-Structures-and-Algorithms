#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<vector<bool>>dp(strlen+1, vector<bool>(tarlen+1, false));
    dp[0][0]=true;
    for(int j=1;j<=tarlen;j++)
    dp[0][j]=false;
    for(int i=1;i<=strlen;i++)
    {
        int flag=true;
        for(int ii=1;ii<=i;ii++)
        {
            if(str[ii-1]!='*')
            {
                flag=false;
                break;
            }
        }
        dp[i][0]=flag;
    }

    for(int i=1;i<=strlen;i++)
    {
        for(int j=1;j<=tarlen;j++)
        {
            if(str[i-1]==tar[j-1]||str[i-1]=='?')
            dp[i][j]=dp[i-1][j-1];
            else if(str[i-1]=='*')
            dp[i][j]=dp[i-1][j]|dp[i][j-1];
            else
            dp[i][j]=false;
        }
    }
    if(dp[strlen][tarlen])
    cout<<"True"<<"\n";
    else
    cout<<"False"<<"\n";
    return 0;
}

/*
IP
ab*cd
abdefcd
OP
True
*/