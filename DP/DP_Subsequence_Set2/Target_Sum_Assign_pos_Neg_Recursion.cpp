#include<bits/stdc++.h>
using namespace std;

int findCountWithSumK(int num, int target, vector<int>&arr)
{
    if(num==0)
    {
        if(target==0&&arr[0]==0)
        return 2;
        if(target==0||arr[0]==target)
        return 1;
        return 0;
    }

    int nottake=findCountWithSumK(num-1, target, arr);

    int take=0;
    if(arr[num]<=target)
    take=findCountWithSumK(num-1, target-arr[num], arr);

    return take+nottake;
}
int main()
{
    int num, diff;
    cin>>num>>diff;
    vector<int>arr(num);
    int total_sum=0;
    for(int i=0;i<num;i++)
    {
    cin>>arr[i];
    total_sum+=arr[i];
    }
    if(total_sum-diff<0||(total_sum-diff)%2!=0)
    return 0;

    int s2=(total_sum-diff)/2;
    int res=findCountWithSumK(num-1, s2, arr);
    cout<<res<<"\n";
    return 0;
}

/*
IP
3 1
0 0 1
OP
4
*/