#include<bits/stdc++.h>
using namespace std;

int findCountWithSumK(int num, int target, vector<int>&arr, vector<vector<int>>&dp)
{
    if(target==0)
    return 1;
    
    if(num==0)
    return (arr[0]==target);

    if(dp[num][target]!=-1)
    return dp[num][target];
    int nottake=findCountWithSumK(num-1, target, arr, dp);

    int take=0;
    if(arr[num]<=target)
    take=findCountWithSumK(num-1, target-arr[num], arr, dp);

    return take+nottake;
}
int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<vector<int>>dp(num, vector<int>(target+1, -1));
    int res=findCountWithSumK(num-1, target, arr, dp);
    cout<<res<<"\n";
    return 0;
}

/*
IP
4 3
1 2 2 3
OP
3
*/