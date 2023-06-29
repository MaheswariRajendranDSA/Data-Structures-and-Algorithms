#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size(), tarlen=tar.size();
    vector<vector<int>>dp(strlen+1, vector<int>(tarlen+1, 0));
    
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
    cout<<strlen+tarlen-dp[strlen][tarlen]<<"\n";
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