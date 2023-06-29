#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size(), tarlen=tar.size();
    vector<vector<int>>dp(strlen+1, vector<int>(tarlen+1, 0));
    int len=strlen+tarlen;
    for(int sl=0;sl<=strlen;sl++)
    dp[sl][0]=0;
    for(int tl=0;tl<=tarlen;tl++)
    dp[0][tl]=0;

    for(int sl=1;sl<=strlen;sl++)
    {
        for(int tl=1;tl<=tarlen;tl++)
        {
            if(str[sl-1]==tar[tl-1])
            dp[sl][tl]=1+dp[sl-1][tl-1];
            else
            dp[sl][tl]=max(dp[sl-1][tl],dp[sl][tl-1]);
        }
    }
   int lcs=dp[strlen][tarlen];
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