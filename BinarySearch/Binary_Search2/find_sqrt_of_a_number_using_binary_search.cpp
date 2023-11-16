#include<bits/stdc++.h>
using namespace std;

int findFloorSqrt(int n){
    int low = 1, high = n;

    while(low <= high)
    {
        long long mid = (low+high)/2;
        long long val = mid*mid;
        if(val <= n)
        {
            low = mid+1;
        }
        else 
            high = mid - 1;
    }
    return high;
}

int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    int n = 28;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int ind = findFloorSqrt(n);
    cout<<"The square root of is: "<<ind;
    return 0;
}
/*
The square root of is: 3
*/