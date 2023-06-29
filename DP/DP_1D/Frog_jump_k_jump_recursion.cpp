#include<bits/stdc++.h>
using namespace std;

int FindFrogKstep(int num, vector<int>&arr, int k)
{
    if(num==0)
    return 0;
    int minstep=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(num-i>=0)
        {
        int jump=FindFrogKstep(num-i,arr, k)+abs(arr[num]-arr[num-i]);
        minstep=min(minstep,jump);
        }
    }
    return minstep;
}
int main()
{
    int num, k;
    cin>>num>>k;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    cout<<FindFrogKstep(num-1, arr, k);
    return 0;
}

/*
IP
6 2
30 10 60 10 60 50
OP
40
*/