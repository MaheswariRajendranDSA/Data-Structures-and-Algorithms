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
    cout<<findMaxSumNonAdSubseq(num-1, arr, dp);
    return 0;
}
/*
3
2 3 4
6
*/