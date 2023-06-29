#include<bits/stdc++.h>
using namespace std;

int findMaxSumNonAdSubseq(int num, vector<int>&arr)
{
    if(num==0)
    return arr[0];
    
    if(num<0) return 0;
    int pick=arr[num]+findMaxSumNonAdSubseq(num-2, arr);

    int notpick=0+findMaxSumNonAdSubseq(num-1,arr);
    return max(pick, notpick);
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    cout<<findMaxSumNonAdSubseq(num-1, arr);
    return 0;
}
/*
3
2 3 4
6
*/