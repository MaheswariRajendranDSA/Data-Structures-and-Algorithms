#include<bits/stdc++.h>
using namespace std;

int findBuyAndSellStock(int ind, int transid, int target, int num, vector<int>&price, vector<vector<int>>&dp)
{
    if(ind==num||transid==2*target)
    return 0;

    if(dp[ind][transid]!=-1)
    return dp[ind][transid];

    if(transid%2==0)
    {
        return dp[ind][transid]=max(-price[ind]+findBuyAndSellStock(ind+1, transid+1, target, num, price, dp), 
        0+findBuyAndSellStock(ind+1, transid, target, num, price, dp));
    }
    else
         return dp[ind][transid]=max(price[ind]+findBuyAndSellStock(ind+1, transid+1, target, num, price, dp), 
         0+findBuyAndSellStock(ind+1, transid, target, num, price, dp));
}
//at max target transaction
int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>price(num, 0);
    for(int i=0;i<num;i++)
    cin>>price[i];
    vector<vector<int>>dp(num+1, vector<int>(2*target+1, -1));
    findBuyAndSellStock(0, 0, target, num, price, dp);
    cout<<dp[0][0]<<"\n";
    return 0;
}
/*
IPa
6 2
3 2 6 5 0 3
OP
7
P
*/