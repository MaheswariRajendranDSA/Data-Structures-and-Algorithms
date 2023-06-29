#include<bits/stdc++.h>
using namespace std;

int findFrogJump(int ind, vector<int>&height,vector<int>&dp)
{
    if(ind==0)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int left=findFrogJump(ind-1,height,dp)+ abs(height[ind]-height[ind-1]);
    int right=INT_MAX;
    if(ind>1)
    right=findFrogJump(ind-2,height,dp)+ abs(height[ind]-height[ind-2]);
    return dp[ind]=min(left,right);
}
int main()
{
    int num;
    cin>>num;
    vector<int>height(num+1);
    vector<int>dp(num,-1);
    for(int i=0;i<num;i++)
    cin>>height[i];
    cout<<findFrogJump(num-1,height,dp);
    return 0;
}
/*
IP
6
30 10 60 10 60 50
OP
40
*/