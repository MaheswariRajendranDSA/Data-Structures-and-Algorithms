#include<bits/stdc++.h>
using namespace std;

int findBuyandSellStock(int ind, int buy, int fees, int num, vector<int>&arr)
{
    long profit=0;
    
    if(ind==num)
    return 0;

    if(buy)
    {
        profit=max(-arr[ind]-fees+findBuyandSellStock(ind+1, 0, fees, num, arr), 
        0+findBuyandSellStock(ind+1, 1, fees, num, arr));
    }
    else
    {
        profit=max(arr[ind]+findBuyandSellStock(ind+1, 1, fees, num, arr), 
        0+findBuyandSellStock(ind+1, 0, fees, num, arr));
    }
    return profit;
}
int main()
{
    int num, fees;
    cin>>num>>fees;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    int res=findBuyandSellStock(0, 1, fees, num, arr);
    cout<<res<<"\n";
    return 0;
}

/*
IP
6 2
1 3 2 8 4 9
OP
8
*/