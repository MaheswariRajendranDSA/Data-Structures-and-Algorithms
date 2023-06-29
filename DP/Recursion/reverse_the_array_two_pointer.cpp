#include<bits/stdc++.h>
using namespace std;

int find_reversethearr(int left, int right, vector<int>&arr,int num)
{
    if(left>=num/2)
    {
        for(int i=0;i<num;i++)
        cout<<arr[i]<<" ";
        return 0;
    }
    swap(arr[left],arr[right]);
    find_reversethearr(left+1,right-1,arr, num);
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    find_reversethearr(0,num-1,arr,num);
    return 0;
}

/*
IP
 4
 1 2 3 4
OP 
4 3 2 1
*/