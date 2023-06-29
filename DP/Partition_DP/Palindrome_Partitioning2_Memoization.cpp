#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int i, int j)
{
    while(i<j)
    {
        if(str[i]!=str[j])
        return false;
        i++;j--;
    }

    return true;
}
int findMinimumCost(int i, string &str, int n, vector<int>&dp)
{
    if(i==n)
    return 0;

    if(dp[i]!=-1)
    return dp[i];

    int mincost=INT_MAX;
    for(int j=i;j<n;j++)
    {
        if(isPalindrome(str, i, j))
        {
            int cost=1+findMinimumCost(j+1, str, n, dp);
            mincost=min(mincost, cost);
        }
    }
    return dp[i]=mincost;
}
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    vector<int>dp(n+2, -1);
    int ans=findMinimumCost(0, str, n, dp)-1;
    cout<<ans<<"\n";
    return 0;
}

/*
IP
bbabcbadcede
OP
4
*/