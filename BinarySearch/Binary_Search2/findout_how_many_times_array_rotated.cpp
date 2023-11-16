#include<bits/stdc++.h>
using namespace std;

int findCount(vector<int> &a)
{
    int n = a.size();
    int low = 0, high = n-1, ans = INT_MAX, index = -1;

    while(low<=high){
        int mid = (low+high)/2;
        
        if(a[low]<=a[high])
        {
            if(a[low]<ans){
                ans = a[low];
                index = low;
            }
            break;
        }
        else if(a[low]<=a[mid]){
                if(a[low]<ans)
                {
                index = low;
                ans = a[low];
                low = mid+1;
                }
        }
        else {
                if(a[mid]<ans)
                {
                index = mid;
                ans = a[mid];
                high = mid-1;
                }
        }
        }
        return index;
    }
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int>a = {12, 16, 26, 1, 3, 6, 9, 10};
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int ind = findCount(a);
    cout<<"The number of time the array rotated is: "<<ind;
    return 0;
}
/*
The number of time the array rotated is: 3
*/