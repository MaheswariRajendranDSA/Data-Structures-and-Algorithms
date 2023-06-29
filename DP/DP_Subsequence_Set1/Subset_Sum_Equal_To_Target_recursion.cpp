#include<bits/stdc++.h>
using namespace std;

bool CheckSubsetsumInTarget(int i, int num, int target, vector<int>&arr)
{
    if(target==0)
    return true;
    if(i==0)
    return (arr[0]==target);
    bool nottake=CheckSubsetsumInTarget(i-1, num, target, arr);
    bool take=false;
    if(target-arr[i]>=0)
    take=CheckSubsetsumInTarget(i-1, num, target-arr[i], arr);
    return take||nottake;
}
int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    if(CheckSubsetsumInTarget(num-1, num-1, target, arr))
    cout<<"TRUE";
    else
    cout<<"FALSE";
    return 0;
}
/*
IP
4 4
1 2 3 4 
OP
TRUE
*/