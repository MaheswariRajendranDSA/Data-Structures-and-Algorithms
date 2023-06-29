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

    return dp[strlen][tarlen]=max(findLomgestCommonSubsequence(strlen, tarlen-1, str, tar, dp),
                   findLomgestCommonSubsequence(strlen-1, tarlen, str, tar, dp));
}
int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<vector<int>>dp(strlen+1, vector<int>(tarlen+1, -1));
    int len=strlen+tarlen;
    int lcs=findLomgestCommonSubsequence(strlen-1, tarlen-1, str, tar, dp);
    int ans=len-2*lcs;
    cout<<ans<<"\n";
    return 0;
}
/*
IP
abcd
efgh
OP
8
*/