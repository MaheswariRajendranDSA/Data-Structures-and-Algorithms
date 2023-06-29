#include<bits/stdc++.h>
using namespace std;

//with cooldown period
int findBuyandSellStock(int ind, int buy, int num, vector<int>&arr, vector<vector<int>>&dp)
{
    long profit=0;
    
    if(ind>=num)
    return 0;

    if(dp[ind][buy]!=-1)
    return dp[ind][buy];

    if(buy)
    {
        profit=max(-arr[ind]+findBuyandSellStock(ind+1, 0, num, arr, dp), 0+findBuyandSellStock(ind+1, 1, num, arr, dp));
    }
    else
    {
        profit=max(arr[ind]+findBuyandSellStock(ind+2, 1, num, arr, dp), 0+findBuyandSellStock(ind+1, 0, num, arr, dp));
    }
    return dp[ind][buy]=profit;
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<vector<int>>dp(num+1, vector<int>(2, -1));
    int res=findBuyandSellStock(0, 1, num, arr, dp);
    cout<<res<<"\n";
    return 0;
}

/*
IP
5
4 9 0 4 10
OP
7
*/