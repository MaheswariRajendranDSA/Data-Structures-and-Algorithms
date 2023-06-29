#include<bits/stdc++.h>
using namespace std;

int findBuyandSellStock(int ind, int buy, int num, vector<int>&arr)
{
    long profit=0;
    
    if(ind==num)
    return 0;

    if(buy)
    {
        profit=max(-arr[ind]+findBuyandSellStock(ind+1, 0, num, arr), 0+findBuyandSellStock(ind+1, 1, num, arr));
    }
    else
    {
        profit=max(arr[ind]+findBuyandSellStock(ind+1, 1, num, arr), 0+findBuyandSellStock(ind+1, 0, num, arr));
    }
    return profit;
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    int res=findBuyandSellStock(0, 1, num, arr);
    cout<<res<<"\n";
    return 0;
}

/*
IP
6
7 1 5 3 6 4
OP
7
*/