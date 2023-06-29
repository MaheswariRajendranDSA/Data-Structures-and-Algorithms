#include<bits/stdc++.h>
using namespace std;

int findMinimumCoins(int num, int target, vector<int>&arr, vector<vector<int>>&dp)
{
    if(num==0)
    {
        if(target%arr[0]==0)
        return target/arr[0];
        else
        return 1e9;
    }

    if(dp[num][target]!=-1)
    return dp[num][target];
    int nottake=findMinimumCoins(num-1, target, arr, dp);

    int take=1e9;
    if(arr[num]<=target)
    take=1+findMinimumCoins(num, target-arr[num], arr, dp);

    return dp[num][target]=min(take, nottake);
}


int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<vector<int>>dp(num, vector<int>(target+1, -1));
    findMinimumCoins(num-1, target, arr, dp);
    cout<<dp[num-1][target]<<"\n";
    return 0;
}

/*
IP
4 11
9 6 5 1
OP
2
*/