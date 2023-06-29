#include<bits/stdc++.h>
using namespace std;

int findSingleSubset(int num, int target, vector<int>&arr, vector<vector<int>>&dp)
{
    if(target==0)
    return dp[num][target]=true;
    
    if(num==0)
    return dp[num][target]=(arr[0]==target);

    if(dp[num][target]!=-1)
    return dp[num][target];

    bool nottake=findSingleSubset(num-1, target, arr, dp);

    bool take=false;
    if(arr[num]<=target)
    take=findSingleSubset(num-1, target-arr[num], arr, dp);

    return dp[num][target]=take||nottake;
    
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    int total_sum=0;
    for(int i=0;i<num;i++)
    {
    cin>>arr[i];
    total_sum+=arr[i];
    }
    vector<vector<int>>dp(num, vector<int>(total_sum+1, -1));
    for(int i=0;i<=total_sum;i++)
    {
        bool partial_res=findSingleSubset(num-1, i, arr, dp);
    }
    int mini=INT_MAX;
    for(int i=0;i<=total_sum;i++)
    {
       if(dp[num-1][i])
       {
        int diff=abs(i-(total_sum-i));
        mini=min(mini, diff);
       }
    }
    cout<<mini<<"\n";
    return 0;
}
/*
IP
4
1 2 3 4
OP
0
*/