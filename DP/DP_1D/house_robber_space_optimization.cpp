#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr)
{
        int num=arr.size();
        int prevf=arr[0];
        int prevs=0;
        for(int i=1;i<num;i++)
        {
        int pick=arr[i];
        if(i>1)
        pick+=prevs;
        int notpick=0+prevf; 
        int curi=max(pick, notpick);
        prevs=prevf;
        prevf=curi;
        }
        return prevf;  
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
    int max1=solve(arr1);
    int max2=solve(arr2);
    cout<<max(max1, max2);
    return 0;
}
/*
IP
4
2 1 4 9
OP
10
*/