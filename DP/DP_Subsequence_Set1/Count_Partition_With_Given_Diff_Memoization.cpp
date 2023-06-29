#include<bits/stdc++.h>
using namespace std;

int findCountWithSumK(int num, int target, vector<int>&arr, vector<vector<int>>&dp)
{
    if(num==0)
    {
        if(target==0&&arr[0]==0)
        return 2;
        if(target==0||arr[0]==target)
        return 1;
        return 0;
    }

    if(dp[num][target]!=-1)
    return dp[num][target];

    int nottake=findCountWithSumK(num-1, target, arr, dp);

    int take=0;
    if(arr[num]<=target)
    take=findCountWithSumK(num-1, target-arr[num], arr, dp);

    return dp[num][target]=take+nottake;
}
int main()
{
    int num, diff;
    cin>>num>>diff;
    vector<int>arr(num);
    int total_sum=0;
    for(int i=0;i<num;i++)
    {
    cin>>arr[i];
    total_sum+=arr[i];
    }
    int s2=(total_sum-diff)/2;
    vector<vector<int>>dp(num, vector<int>(s2+1, -1));

    if(total_sum-diff<0||(total_sum-diff)%2!=0)
    return 0;

    findCountWithSumK(num-1, s2, arr, dp);
    cout<<dp[num-1][s2]<<"\n";
    return 0;
}

/*
IP
4 3 
5 2 6 4
OP
1
*/