#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int strlen=str.size();
    string tar;
    tar=str;
    reverse(tar.begin(), tar.end());
    vector<vector<int>>dp(strlen+1, vector<int>(strlen+1, 0));
    
    for(int sl=0;sl<=strlen;sl++)
    dp[sl][0]=0;
    for(int tl=0;tl<=strlen;tl++)
    dp[0][tl]=0;

    for(int sl=1;sl<=strlen;sl++)
    {
        for(int tl=1;tl<=strlen;tl++)
        {
            if(str[sl-1]==tar[tl-1])
            dp[sl][tl]=1+dp[sl-1][tl-1];
            else
            dp[sl][tl]=max(dp[sl-1][tl],dp[sl][tl-1]);
        }
    }
    int palindrome=dp[strlen][strlen];
    cout<<strlen-palindrome<<"\n";
    return 0;
}

/*
IP
codingninjas
OP
7
*/