#include<bits/stdc++.h>
using namespace std;

int findMaximumSum(int i, vector<int>&arr, int n, int k, vector<int>&dp)
{
    if(i==n)
    return 0;

    if(dp[i]!=-1)
    return dp[i];

    int len=0, maxielement=INT_MIN, resmax=INT_MIN;
    for(int j=i;j<min(i+k,n);j++)
    {
        len++;
        maxielement=max(maxielement, arr[j]);
        int sum=len*maxielement+findMaximumSum(j+1, arr, n, k, dp);
        resmax=max(resmax, sum);
    }
    return dp[i]=resmax;
}
int main()
{
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int>dp(n+2, -1);
    findMaximumSum(0, arr, n, k, dp);
    cout<<dp[0]<<"\n";
    return 0;
}

/*
IP
7 3
1 15 7 9 2 5 10
OP
84
*/
