#include<bits/stdc++.h>
using namespace std;

int findMaxCoinsToBurst(int i, int j, vector<int>&arr, int n, vector<vector<int>>&dp)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int maxi=INT_MIN;
    for(int ind=i;ind<=j;ind++)
    {
        int cost=arr[i-1]*arr[ind]*arr[j+1]+findMaxCoinsToBurst(i, ind-1, arr, n, dp)+
        findMaxCoinsToBurst(ind+1, j, arr, n, dp);
        maxi=max(maxi, cost);
    }
    return dp[i][j]=maxi;
}

int maxcoins(vector<int>&arr, int n, vector<vector<int>>&dp)
{
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    return findMaxCoinsToBurst(1, n, arr, n, dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<vector<int>>dp(n+3, vector<int>(n+3, -1));
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int ans=maxcoins(arr, n, dp);
    int len=arr.size();
    cout<<ans<<"\n";
}
/*
IP
4
3 1 5 8
OP
167
*/