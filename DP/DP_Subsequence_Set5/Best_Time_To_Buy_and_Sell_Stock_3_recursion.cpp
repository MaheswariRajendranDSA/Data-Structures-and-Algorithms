#include<bits/stdc++.h>
using namespace std;

int findBuyAndSellStock(int ind, int buy, int num, vector<int>&price, int cap)
{
    if(ind==num||cap==0)
    return 0;
    if(buy)
    {
        return max(-price[ind]+findBuyAndSellStock(ind+1, 0, num, price, cap), 0+findBuyAndSellStock(ind+1, 1, num, price, cap));
    }
    else
         return max(price[ind]+findBuyAndSellStock(ind+1, 1, num, price, cap-1), 0+findBuyAndSellStock(ind+1, 0, num, price, cap));
}
//at max 2 transaction
int main()
{
    int num;
    cin>>num;
    vector<int>price(num, 0);
    for(int i=0;i<num;i++)
    cin>>price[i];
    int res=findBuyAndSellStock(0, 1, num, price, 2);
    cout<<res<<"\n";
    return 0;
}
/*
IP
9
3 3 5 0 0 0 3 1 4
OP
6
P
*/