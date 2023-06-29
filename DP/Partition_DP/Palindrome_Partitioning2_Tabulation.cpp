#include<bits/stdc++.h>
using namespace std;

bool isPlaindrome(int i, int j, string &str)
{
    while(i<j)
    {
        if(str[i]!=str[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    vector<int>dp(n+3, 0);
    for(int i=n-1;i>=0;i--)
    {
        int mincost=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPlaindrome(i, j, str))
            {
                int cost=1+dp[j+1];
                mincost=min(mincost, cost);
            }
        }
        dp[i]=mincost;
    }
    cout<<dp[0]-1;
    return 0;
}
/*
IP
bbabcbadcede
OP
4
*/