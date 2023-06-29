#include<bits/stdc++.h>
using namespace std;

int findBuyAndSellStock(int ind, int buy, int num, vector<int>&price, int cap, vector<vector<vector<int>>>&dp)
{
    if(ind==num||cap==0)
    return 0;
    if(dp[ind][buy][cap]!=-1)
    return dp[ind][buy][cap];
    if(buy)
    {
        return dp[ind][buy][cap]=max(-price[ind]+findBuyAndSellStock(ind+1, 0, num, price, cap, dp), 
        0+findBuyAndSellStock(ind+1, 1, num, price, cap, dp));
    }
    else
         return dp[ind][buy][cap]=max(price[ind]+findBuyAndSellStock(ind+1, 1, num, price, cap-1, dp),
          0+findBuyAndSellStock(ind+1, 0, num, price, cap, dp));
}
//at max 2 transaction
int main()
{
    int num;
    cin>>num;
    vector<int>price(num, 0);
    for(int i=0;i<num;i++)
    cin>>price[i];
    vector<vector<vector<int>>>dp(num+1, vector<vector<int>>(2, vector<int>(3 ,-1)));
    findBuyAndSellStock(0, 1, num, price, 2, dp);
    cout<<dp[0][1][2]<<"\n";
    return 0;
}
/*
IP
9
3 3 5 0 0 0 3 1 4
OP
6
P
*/