#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> &a, int &target)
{
    int n = a.size();
    int low = 0, high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid] == target) return mid;
        
        if(a[low] == a[mid] && a[mid]== a[high]){
            low--;
            high++;
            continue;
        }
        if(a[low]<=a[mid])
        {
            if(a[low]<= target && target <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(a[mid] <= target && target <= a[high])
                low = mid+1;
             else 
                high = mid-1;
        }
    }
    return -1;
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int>a = {6, 6, 6, 6, 6, 6, 6, 6};
    int target = 6;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int ind = binarysearch (a, target);
    if(ind == -1)
        cout<<"The target is not present";
    else
        cout<<"The target index is:"<<ind;
    return 0;
}
/*
The target index is:3
*/