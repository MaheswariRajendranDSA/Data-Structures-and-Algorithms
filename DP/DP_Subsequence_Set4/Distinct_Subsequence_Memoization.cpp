#include<bits/stdc++.h>
using namespace std;

int findDistinctSubsequence(int strlen, int tarlen, string &str, string &tar, vector<vector<int>>&dp)
{
    if(tarlen<0)
    return 1;
    if(strlen<0)
    return 0;

    if(dp[strlen][tarlen]!=-1)
    return dp[strlen][tarlen];

    if(str[strlen]==tar[tarlen])
    {
        return findDistinctSubsequence(strlen-1, tarlen-1, str, tar, dp)+
            findDistinctSubsequence(strlen-1, tarlen, str, tar, dp);
    }
    return findDistinctSubsequence(strlen-1, tarlen, str, tar, dp);
}
int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<vector<int>>dp(strlen, vector<int>(tarlen,-1));
    int res=findDistinctSubsequence(strlen-1, tarlen-1, str, tar, dp);
    cout<<res<<"\n";
    return 0;
}

/*
IP
babgbag
bag
OP
5*/