#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];

    vector<vector<int>>dp(num+2, vector<int>(2*target+1, 0));

    for(int ind=num-1;ind>=0;ind--)
    {
        for(int transid=2*target-1;transid>=0;transid--)
        {
            if(transid%2==0)
            dp[ind][transid]=max(-price[ind]+dp[ind+1][transid+1], 0+dp[ind+1][transid]);
            else
            dp[ind][transid]=max(price[ind]+dp[ind+1][transid+1], 0+dp[ind+1][transid]);
        }
    }
    cout<<dp[0][0];
}