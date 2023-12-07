#include<bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    if(n1>n2) return median(b, a);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1)/2;
    int n = n1+n2;

    while(low<high){
        int mid1 = (low+high)>>1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1<n1) r1 = a[mid1];
        if(mid2<n2) r2 = b[mid2];

        if(mid1 - 1>=0) l1 = a[mid1 - 1];
        if(mid2 - 1>=0) l2 = a[mid2 - 1];
        if(l1<=r2 && l2<=r1){
            if(n%2 == 1)return max(l1, l2);
        }
        return (double)(max(l1, l2)+min(r1, r2))/2.0;
    }
}
int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}

/*
The median of two sorted array is 6.0
*/