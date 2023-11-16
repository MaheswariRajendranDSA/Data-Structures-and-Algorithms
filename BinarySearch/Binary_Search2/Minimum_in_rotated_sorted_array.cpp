#include<bits/stdc++.h>
using namespace std;

int findMinimum(vector<int> &a)
{
    int n = a.size();
    int low = 0, high = n-1, ans = INT_MAX;

    while(low<=high){
        int mid = (low+high)/2;
        
        if(a[low]<=a[high])
        {
            ans = min(ans, a[low]);
            break;
        }
        else if(a[low]<=a[mid]){
                ans = min(ans, a[low]);
                low = mid+1;
        }
        else {
                ans = min(ans, a[mid]);
                high = mid-1;
        }
        }
        return ans;
    }
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int>a = {12, 16, 26, 1, 3, 6, 9, 10};
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int ind = findMinimum (a);
        cout<<"The minimum element is:"<<ind;
    return 0;
}
/*
The minimum element is:1
*/