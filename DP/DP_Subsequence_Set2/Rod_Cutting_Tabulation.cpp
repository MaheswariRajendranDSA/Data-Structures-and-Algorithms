#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];
     
    vector<vector<int>>dp(num, vector<int>(num+1, 0));

    for(int i=0;i<=num;i++)
    dp[0][i]=(i*price[0]);

    for(int ind=1;ind<num;ind++)
    {
        for(int len=0;len<=num;len++)
            {
                int nottake=dp[ind-1][len];

                int take=-1e9;
                int rodlength=ind+1;
                if(rodlength<=len)
                take=dp[ind][len-rodlength]+price[ind];

                dp[ind][len]=max(take, nottake);
            }
    }
    cout<<dp[num-1][num];
    return 0;
}


/*
IP
5
2 5 7 8 10
OP
12
*/