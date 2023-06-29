#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];
    vector<vector<vector<int>>>dp(num+1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int ind=num-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=2;cap++)
            {
                if(buy==1)
                dp[ind][buy][cap]=max(-price[ind]+dp[ind+1][0][cap], 0+dp[ind+1][1][cap]);
                else
                dp[ind][buy][cap]=max(price[ind]+dp[ind+1][1][cap-1], 0+dp[ind+1][0][cap]);
            }
        }
    }
    cout<<dp[0][1][2]<<"\n";
    return 0;
}

/*
IP
9
3 3 5 0 0 0 3 1 4
OP
6
*/