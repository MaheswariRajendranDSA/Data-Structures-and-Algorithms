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
    vector<int>arr1;
    vector<int>arr2;
    if(num==1) return arr[0];
    for(int i=0;i<num;i++)
    {
        if(i!=0)
        arr1.push_back(arr[i]);
        if(i!=num-1)
        arr2.push_back(arr[i]);
    }
    cout<<max(findMaxSumNonAdSubseq(num-2, arr1), findMaxSumNonAdSubseq(num-2, arr2));
    return 0;
}
/*
4
2 1 4 9
10
*/