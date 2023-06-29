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
    findLomgestCommonSubsequence(strlen, tarlen, str, tar, dp);

    int length=dp[strlen][tarlen];

    int i=strlen, j=tarlen;
    string ans="";
    int index=length-1;
    for(int i=0;i<length;i++)
    ans+='#';
    while(i>0&&j>0)
    {
        if(str[i-1]==tar[j-1])
        {
            ans[index]=str[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        j--;
    }
    cout<<ans;
    return 0;
}

/*
IP
acd
ced

OP
cd
*/