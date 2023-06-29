#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>dp(num+1, 1), hash(num, 1);;
    int maxi=-1;
    int lastIndex=-1;
    for(int i=0;i<num;i++)
    {
        hash[i]=i;
        for(int prev=0;prev<i;prev++)
        {
            if(arr[i]>arr[prev]&&1+dp[prev]>dp[i])
            {
            dp[i]=1+dp[prev];
            hash[i]=prev;
            }
        }
        if(dp[i]>maxi)
        {
            maxi=dp[i];
            lastIndex=i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex)
    {
        lastIndex=hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for(auto it:temp)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}

/*
IP
8
10 9 2 5 3 7 101 18
OP
2 5 7 101
*/