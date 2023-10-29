#include<bits/stdc++.h>
using namespace std;
 
void find_reverse(int index, int num, vector<int>&arr)
{
    if(index>=num/2)
    {
        for(int i=0;i<num;i++)
        cout<<arr[i]<<" ";
        return;
    }
    swap(arr[index],arr[num-index-1]);
    find_reverse(index+1,num,arr);
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    find_reverse(0, num, arr);
    return 0;
}

/*
IP
 4
 1 2 3 4
OP 
4 3 2 1
*/