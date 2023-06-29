#include<bits/stdc++.h>
using namespace std;

int findLomgestCommonSubsequence(int strlen, int tarlen, string &str, string &tar, vector<vector<int>>&dp)
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
    int total_len=strlen+tarlen;
    vector<vector<int>>dp(strlen+1, vector<int>(tarlen+1, -1));
    int answer=total_len-findLomgestCommonSubsequence(strlen, tarlen, str, tar, dp);
    cout<<answer<<"\n";
    
    int i=strlen, j=tarlen;
    string ans="";
    while(i>0&&j>0)
    {
        if(str[i-1]==tar[j-1])
        {
            ans+=str[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            ans+=str[i-1];
            i--;
        }
        else
        {
            ans+=tar[j-1];
            j--;
        }
    }
    while(i>0)
    {
        ans+=str[i-1];
        i--;
    }

  while(j>0)
    {
        ans+=tar[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
    return 0;
}

/*
IP
abcde
abn
OP
6
abcden
*/