#include<bits/stdc++.h>
using namespace std;

int findNumberOfSubseq(int index, int target, vector<int>&arr, int num)
{
    if(index==num)
    {
        if(target==0)
        return 1;
        else
        return 0;
    }
    int include=0;
    if(target-arr[index]>=0)
    include=findNumberOfSubseq(index+1, target-arr[index], arr, num);
    int notinclude=findNumberOfSubseq(index+1, target, arr, num);
    return include+notinclude;
}
int main()
{
    int num,target;
    cin>>num>>target;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    int res=findNumberOfSubseq(0, target, arr, num);
    cout<<res<<"\n";
    return 0;
}

/*
IP
4 3
1 2 2 3
OP
3
*/