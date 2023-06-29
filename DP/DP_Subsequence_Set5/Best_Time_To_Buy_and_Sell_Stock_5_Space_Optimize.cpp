#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];

    vector<vector<int>>dp(num+2, vector<int>(2, 0));

    // no need of base condition 
    dp[num][0]=dp[num][1]=0;
                
    for(int ind=num-1;ind>=0;ind--)
    {
        dp[ind][1]=max(-arr[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
        dp[ind][0]=max(arr[ind]+dp[ind+2][1], 0+dp[ind+1][0]);
    }
    cout<<dp[0][1];
}

/*
IP
5
4 9 0 4 10
OP
11
*/