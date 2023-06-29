#include<bits/stdc++.h>
using namespace std;

bool checkpossibility(string &s1, string &s2)
{
    if(s1.size()!=s2.size()+1)
    return false;
    int first=0;
    int second=0;
    while(first<s1.size())
    {
        if(s1[first]==s2[second])
        {
            first++;
            second++;
        }
        else 
        {
            first++;
        }
    }
    if(first==s1.size()&&second==s2.size())
    return true;
    return false;
}

bool comp(string &s1, string &s2)
{
    return s1.size()<s2.size();
}
int main()
{
    int num;
    cin>>num;
    vector<string>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    int maxi=0;
    sort(arr.begin(), arr.end(), comp);
    vector<int>dp(num, 1);
    for(int ind=0;ind<num;ind++)
    {
        for(int prev=0;prev<ind;prev++)
        {
            if(checkpossibility(arr[ind], arr[prev])&&1+dp[prev]>dp[ind])
            {
                dp[ind]=dp[prev]+1;
            }
        }
        if(dp[ind]>maxi)
        maxi=dp[ind];
    }
    cout<<maxi<<"\n";
}
/*
IP
6
a b ba bca bda bdca
OP
4
*/