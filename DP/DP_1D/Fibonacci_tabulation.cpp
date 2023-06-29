#include<bits/stdc++.h>
using namespace std;


int main()
{
    int num;
    cin>>num;
    vector<int>dp(num+1,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=num;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[num];
    return 0;
}
/*
IP
4
OP
3
*/