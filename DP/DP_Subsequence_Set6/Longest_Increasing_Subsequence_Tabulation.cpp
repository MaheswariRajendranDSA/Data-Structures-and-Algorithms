#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<vector<int>>dp(num+2, vector<int>(num+2, 0));
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    for(int ind=num-1;ind>=0;ind--)
    {
        for(int prev=ind-1;prev>=-1;prev--)
        {
            int len=0+dp[ind+1][prev+1];
            if(prev==-1||arr[ind]>arr[prev])
            len=max(len,1+dp[ind+1][ind+1]);
            dp[ind][prev+1]=len;
        }
    }
    cout<<dp[0][-1+1]<<"\n";
    return 0;
}

/*
IP
8
10 9 2 5 3 7 101 8
OP
4
*/
