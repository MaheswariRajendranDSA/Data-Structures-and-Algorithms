#include<bits/stdc++.h>
using namespace std;

double median (vector<int> &a, vector<int> &b){
    int n1 = a.size(), n2 = b.size();
    vector<int> arr;
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(a[i]<a[j])
            arr.push_back(a[i++]);
        else
            arr.push_back(b[j++]);
    }

    while(i<n1)
        arr.push_back(a[i++]);
    while(j<n2)
        arr.push_back(b[j++]);
    int n = n1+n2;
    if(n%2 == 1)
        return arr[n/2];
    else
        return (double)((double)arr[n/2])+(double)(arr[n/2-1])/2.0;
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