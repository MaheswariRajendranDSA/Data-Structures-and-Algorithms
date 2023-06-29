#include<bits/stdc++.h>
using namespace std;

int findLongestIncreasingSubsequence(int ind, int prevInd, int num, vector<int>&arr, vector<vector<int>>&dp)
{
    if(ind==num)
    return 0;

    if(dp[ind][prevInd+1]!=-1)
    return dp[ind][prevInd+1];

    int len = 0+findLongestIncreasingSubsequence(ind+1, prevInd, num, arr, dp);
    if(prevInd==-1||arr[ind]>arr[prevInd])
    {
        len = max(len, 1+findLongestIncreasingSubsequence(ind+1, ind, num, arr, dp));
    }
    return dp[ind][prevInd+1]=len;
 }
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>>dp(num, vector<int>(num+2, -1));
    int res=findLongestIncreasingSubsequence(0, -1, num, arr, dp);
    cout<<dp[0][-1+1]<<"\n";
    return 0;
}

/*
IP
8
10 9 2 5 3 7 101 8
OP
4
*/