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
    string str;
    cin>>str;
    int strlen=str.size();
    string tar;
    tar=str;
    reverse(str.begin(), str.end());
    vector<vector<int>>dp(strlen+1, vector<int>(strlen+1, -1));
    findLomgestCommonSubsequence(strlen, strlen, tar, str, dp);
    cout<<dp[strlen][strlen];
    return 0;
}
/*
IP
bbabcbcab
OP
7
*/