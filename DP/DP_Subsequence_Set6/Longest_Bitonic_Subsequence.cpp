#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    int maxi=0;
    vector<int>dp1(num,1);
    for(int ind=0;ind<num;ind++)
    {
        for(int prev=0;prev<ind;prev++)
        {
            if(arr[ind]>arr[prev]&&1+dp1[prev]>dp1[ind])
            {
                dp1[ind]=1+dp1[prev];
            }
        }
    }
      vector<int>dp2(num,1);
    for(int ind=num-1;ind>=0;ind--)
    {
        for(int prev=num-1;prev>ind;prev--)
        {
            if(arr[ind]>arr[prev]&&1+dp2[prev]>dp2[ind])
            {
                dp2[ind]=1+dp2[prev];
            }
        }
    }
    for(int ind=0;ind<num;ind++)
    {
        maxi=max(maxi, dp1[ind]+dp2[ind]-1);
    }
    cout<<maxi<<"\n";
}
/*
IP
8
1 11 2 10 4 5 2 1
OP
6
*/