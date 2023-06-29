#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, k;
    cin>>num>>k;
    vector<int>dp(num,-1);
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    dp[0]=0;
    for(int i=1;i<num;i++)
    {
        int minsteps=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
                minsteps=min(minsteps,jump);
            }
        }
        dp[i]=minsteps;
    }
    cout<<dp[num-1];
    return 0;
}

/*
IP
6 2
30 10 60 10 60 50
OP
40
*/