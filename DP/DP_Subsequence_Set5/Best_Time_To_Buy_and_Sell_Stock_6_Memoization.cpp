#include<bits/stdc++.h>
using namespace std;

int findBuyandSellStock(int ind, int buy, int num, int fees, vector<int>&arr, vector<vector<int>>&dp)
{
    long profit=0;
    
    if(ind==num)
    return 0;

    if(dp[ind][buy]!=-1)
    return dp[ind][buy];

    if(buy)
    {
        profit=max(-arr[ind]+findBuyandSellStock(ind+1, 0, num, fees, arr, dp), 
        0+findBuyandSellStock(ind+1, 1, num, fees, arr, dp));
    }
    else
    {
        profit=max(arr[ind]-fees+findBuyandSellStock(ind+1, 1, num, fees, arr, dp), 
        0+findBuyandSellStock(ind+1, 0, num, fees, arr, dp));
    }
    return dp[ind][buy]=profit;
}
int main()
{
    int num, fees;
    cin>>num>>fees;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<vector<int>>dp(num+1, vector<int>(2, -1));
    int res=findBuyandSellStock(0, 1, num, fees, arr, dp);
    cout<<res<<"\n";
    return 0;
}

/*
IP
6 2
1 3 2 8 4 9
OP
8
*/