#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++;
        end --;
    }
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int d = 3;
    
    reverse(arr, 0, n-d-1);
    reverse(arr, n-d, n-1);
    reverse(arr, 0, n-1);
    cout<<"The rotataed array is : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
/*
The rotataed array is : 3 4 5 1 2
*/