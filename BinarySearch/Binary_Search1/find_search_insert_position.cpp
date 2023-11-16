#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &a, int target)
{
    int n = a.size();
    int low = 0, high = n-1, ans=n;

    while(low<=high){
        int mid = (low+high)/2;
        if(target <= a[mid])
        {
            ans = mid;
            high = mid-1;
        }
        else 
            low = mid+1;
    }
    return ans;
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int>a = {3, 4, 7, 9, 12, 16, 17};
    int target = 6;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int ind = lowerbound (a, target);
        cout<<"The target index for lowerbound is:"<<ind<<"\n";
    return 0;
}

/*
The target index for lowerbound is:2
*/