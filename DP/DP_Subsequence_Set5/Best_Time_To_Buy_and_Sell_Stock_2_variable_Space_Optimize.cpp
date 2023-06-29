#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];

    long frontnotbuy, frontbuy, curnotbuy, curbuy;
    frontnotbuy=frontbuy=0;
                
    for(int i=num-1;i>=0;i--)
    {
            curnotbuy=max(arr[i]+frontbuy, 0+frontnotbuy);
            curbuy=max(-arr[i]+frontnotbuy, 0+frontbuy);
            frontnotbuy=curnotbuy;
            frontbuy=curbuy;
    }
    cout<<frontbuy;
}

/*
IP
6
7 1 5 3 6 4
OP
7
*/