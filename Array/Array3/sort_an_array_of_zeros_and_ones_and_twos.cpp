//Dutch national flag algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
    int n = arr.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
            mid++;
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    cout<<"The array in sorted order is : ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}
/*
The array in sorted order is : 0 0 0 0 0 1 1 1 1 2 2
*/