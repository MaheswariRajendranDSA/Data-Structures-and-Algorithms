#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>dp(num+1,0);
    dp[0]=0;
    vector<int>height(num+1);
    for(int i=0;i<num;i++)
    cin>>height[i];
    for(int i=1;i<num;i++)
    {
        int left=dp[i-1]+ abs(height[i]-height[i-1]);
        int right=INT_MAX;
        if(i>1)
        right=dp[i-2]+ abs(height[i]-height[i-2]);
        dp[i]=min(left,right);
    }
    cout<<dp[num-1];
    return 0;
}
/*
IP
6
30 10 60 10 60 50
OP
40
*/