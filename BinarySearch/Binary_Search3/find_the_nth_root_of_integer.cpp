#include<bits/stdc++.h>
using namespace std;

int findRoot ( int mid, int n, int m){
    int ans  = 1;
    for(int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if(ans > m) return 2;
    }
         if(ans == m) return 1;
        return 0;
}
int findNthRoot(int n, int m){
    int low = 1, high = m;
    while( low <= high)
    {
        int mid  = (low+high)/2;
        int midNth = findRoot(mid, n, m);
        if(midNth == 1) return mid;
        else if(midNth == 0) low = mid + 1;
        else high = mid + 1;
    }
    return -1;
}

int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    int n = 3, m = 27;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int ind = findNthRoot(n, m);
    cout<<"The Nth root of integer is: "<<ind;
    return 0;
}
/*
The Nth root of integer is: 3
*/