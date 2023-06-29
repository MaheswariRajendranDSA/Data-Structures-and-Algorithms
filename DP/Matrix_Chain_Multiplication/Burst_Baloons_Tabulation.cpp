#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<vector<int>>dp(n+3, vector<int>(n+3, 0));
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j)
            continue;
            int maxi=INT_MIN;
            for(int ind=i;ind<=j;ind++)
            {
                int cost=arr[i-1]*arr[ind]*arr[j+1]+dp[i][ind-1]+dp[ind+1][j];
                maxi=max(maxi, cost);
            }
            dp[i][j]=maxi;
        }
    }
    cout<<dp[1][n];
}

/*
IP
4
3 1 5 8
OP
167
*/