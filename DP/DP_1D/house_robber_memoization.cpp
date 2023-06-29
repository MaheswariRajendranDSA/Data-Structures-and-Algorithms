#include<bits/stdc++.h>
using namespace std;

int findMaxSumNonAdSubseq(int num, vector<int>&arr, vector<int>&dp)
{
    if(num==0)
    return arr[0];
    if(num<0) return 0;
    if(dp[num]!=-1)
    return dp[num];

    int pick=arr[num]+findMaxSumNonAdSubseq(num-2, arr, dp);

    int notpick=0+findMaxSumNonAdSubseq(num-1,arr, dp);
    return dp[num]=max(pick, notpick);
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    vector<int>dp(num, -1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>arr1;
    vector<int>arr2;
    for(int i=0;i<num;i++)
    {
        if(i!=0)
        arr1.push_back(arr[i]);
        if(i!=num-1)
        arr2.push_back(arr[i]);
    }
    int ans1=findMaxSumNonAdSubseq(num-2, arr1,dp);
    for(int i=0;i<num;i++)
    dp[i]=-1;
     int ans2=findMaxSumNonAdSubseq(num-2, arr2,dp);
     cout<<max(ans1, ans2);
    return 0;
}
/*
4
2 1 4 9
10
*/