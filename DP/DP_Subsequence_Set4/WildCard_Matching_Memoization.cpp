#include<bits/stdc++.h>
using namespace std;

bool findWildCardMatching(int strlen, int tarlen, string str, string tar, vector<vector<int>>&dp)
{
    if(strlen==0&&tarlen==0)
    return true;
    if(strlen==0&&tarlen>0)
    return false;
    if(strlen>0&&tarlen==0)
    {
        for(int ii=1;ii<=strlen;ii++)
        {
            if(str[strlen-1]!='*')
            return false;
        }
        return true;
    } 
    if(dp[strlen][tarlen]!=-1)
    return dp[strlen][tarlen];

    if(str[strlen-1]==tar[tarlen-1]||str[strlen-1]=='?')
    return dp[strlen][tarlen]=findWildCardMatching(strlen-1, tarlen-1, str, tar, dp);
    if(str[strlen-1]=='*')
    return dp[strlen][tarlen]=findWildCardMatching(strlen-1, tarlen, str, tar, dp)||findWildCardMatching(strlen, tarlen-1, str, tar, dp);
    return dp[strlen][tarlen]=false;
}
int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<vector<int>>dp(strlen+1, vector<int>(tarlen+1, -1));
    bool res=findWildCardMatching(strlen, tarlen, str, tar, dp);
    if(res)
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