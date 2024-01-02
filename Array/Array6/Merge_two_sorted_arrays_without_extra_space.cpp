#include<bits/stdc++.h>
using namespace std;

void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int left, int right){
    if(arr1[left] > arr2[right])
        swap(arr1[left], arr2[right]);
}
void merge(vector<int> &arr1, vector<int> &arr2, int n, int m){
    int len  = n+m;
    int gap = len/2 + len%2;
    while(gap > 0){
        int left = 0;
        int right = left+gap;
        while(right<len){
           if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if(gap == 1) break;
        gap = gap/2 + gap%2;
    }
}
int main(){
    vector<int> arr1 = {1, 3, 5, 7}, arr2 = {0, 2, 6, 8, 9};
    int n = arr1.size();
    int m = arr2.size();
    merge(arr1, arr2, n, m);
    cout<<"The sorted array is:"<<"\n";
    for(int i = 0;i<n;i++)
        cout<<arr1[i]<<" ";
        cout<<"\n";
    for(int j = 0; j <m;j++)
        cout<<arr2[j]<<" ";
    return 0;
}

/*
The sorted array is: 
0 1 2 3 
5 6 7 8 9
*/