#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    int mini=arr[0];
    int profit=0;
    int cost=0;
    for(int i=1;i<num;i++)
    {
        cost=arr[i]-mini;
        profit=max(profit, cost);
        mini=min(mini, arr[i]);
    }
    cout<<profit<<"\n";
}

/*
IP
6
7 1 5 3 6 4
OP
5
*/