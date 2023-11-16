#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &a, int target)
{
    int n = a.size();
    int low = 0, high = n-1, ans=n;

    while(low<=high){
        int mid = (low+high)/2;
        if(target >= a[mid])
        {
            ans = a[mid];
            low = mid+1;
        }
        else 
            high = mid-1;
    }
    return ans;
}
int findCeil(vector<int> &a, int target)
{
    int n = a.size();
    int low = 0, high = n-1, ans=n;

    while(low<=high){
        int mid = (low+high)/2;
         if(target <= a[mid])
         {
            ans = a[mid];
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
    vector<int>a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int ind = findFloor (a, target);
        cout<<"The floor of the element is:"<<ind<<"\n";
    int ind1 = findCeil (a, target);
        cout<<"The ceil of the element is:"<<ind1;
    return 0;
}
/*
The floor of the element is:6
The ceil of the element is:6
*/