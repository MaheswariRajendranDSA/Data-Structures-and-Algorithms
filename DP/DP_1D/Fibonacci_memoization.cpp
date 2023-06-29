#include<bits/stdc++.h>
using namespace std;

int findFibonacci(int ind,int num, vector<int>&dp)
{
    if(ind<=1)
    return ind;
    if(dp[ind]!=-1)
    return dp[ind];
    int left=findFibonacci(ind-1,num,dp);
    int right=findFibonacci(ind-2,num,dp);
    return dp[ind]=left+right;
}
int main()
{
    int num;
    cin>>num;
    vector<int>dp(num+1,-1);
    cout<<findFibonacci(num,num,dp);
    return 0;
}
/*
IP
4
OP
3
*/