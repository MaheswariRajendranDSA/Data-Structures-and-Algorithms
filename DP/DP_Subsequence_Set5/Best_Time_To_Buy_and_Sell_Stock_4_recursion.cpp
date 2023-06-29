#include<bits/stdc++.h>
using namespace std;

int findBuyAndSellStock(int ind, int transid, int target, int num, vector<int>&price)
{
    if(ind==num||transid==2*target)
    return 0;
    if(transid%2==0)
    {
        return max(-price[ind]+findBuyAndSellStock(ind+1, transid+1, target, num, price), 
        0+findBuyAndSellStock(ind+1, transid, target, num, price));
    }
    else
         return max(price[ind]+findBuyAndSellStock(ind+1, transid+1, target, num, price), 
         0+findBuyAndSellStock(ind+1, transid, target, num, price));
}
//at max target transaction
int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>price(num, 0);
    for(int i=0;i<num;i++)
    cin>>price[i];
    int res=findBuyAndSellStock(0, 0, target, num, price);
    cout<<res<<"\n";
    return 0;
}
/*
IP
6 2
3 2 6 5 0 3
OP
7
P
*/