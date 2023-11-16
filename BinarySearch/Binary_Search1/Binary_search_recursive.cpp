#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> &a, int target, int low, int high)
{
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(a[mid] == target) return mid;
    else if(target > a[mid])
        return binarysearch(a, target, mid+1, high);
    else 
        return binarysearch(a, target, low, mid-1);
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int>a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int ind = binarysearch (a, target, 0, a.size()-1);
    if(ind == -1)
        cout<<"The target is not present";
    else
        cout<<"The target index is:"<<ind;
    return 0;
}

/*
The target index is:2
*/