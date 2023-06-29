#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>dp(num+1, 1);
    int maxi=0;
    for(int i=0;i<num;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(arr[i]>arr[prev])
            dp[i]=max(dp[i],1+dp[prev]);
        }
        maxi=max(maxi, dp[i]);
    }
    cout<<maxi<<"\n";
    return 0;
}
/*
IP
8
10 9 2 5 3 7 101 8
OP
4
*/