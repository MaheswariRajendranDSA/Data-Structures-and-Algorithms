#include<bits/stdc++.h>
using namespace std;

int findEditDistance(int strlen, int tarlen, string &str, string &tar, vector<vector<int>>&dp)
{
    if(strlen<0)
    return tarlen+1;

    if(tarlen<0)
    return strlen+1;
    
    if(dp[strlen][tarlen]!=-1)
    return dp[strlen][tarlen];

    if(str[strlen]==tar[tarlen])
    return dp[strlen][tarlen]=findEditDistance(strlen-1, tarlen-1, str, tar, dp);

    return dp[strlen][tarlen]=1+min({
        findEditDistance(strlen, tarlen-1, str, tar, dp),
        findEditDistance(strlen-1, tarlen, str, tar, dp),
        findEditDistance(strlen-1, tarlen-1, str, tar, dp)});
}
int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<vector<int>>dp(strlen, vector<int>(tarlen, -1));
    findEditDistance(strlen-1, tarlen-1, str, tar, dp);
    cout<<dp[strlen-1][tarlen-1]<<"\n";
    return 0;
}

/*
IP
horse
ros
OP
3
*/