#include<bits/stdc++.h>
using namespace std;

int findLomgestCommonSubsequence(int strlen, int tarlen, string str, string tar, vector<vector<int>>&dp)
{
    if(strlen==0 || tarlen==0)
    return 0;

    if(dp[strlen][tarlen]!=-1)
    return dp[strlen][tarlen];

    if(str[strlen-1]==tar[tarlen-1])
    {
        return dp[strlen][tarlen]=1+findLomgestCommonSubsequence(strlen-1, tarlen-1, str, tar, dp);
    }

    return 0;
}
int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<vector<int>>dp(strlen+1, vector<int>(tarlen+1, -1));
    findLomgestCommonSubsequence(strlen, tarlen, str, tar, dp);
    cout<<dp[strlen][tarlen];
    return 0;
}
/*
IP
abcd
amcd
OP
2
*/