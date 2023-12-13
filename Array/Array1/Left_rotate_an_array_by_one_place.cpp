#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int length = arr.size();
    int temp = arr[0];
    for(int i=1;i<length;i++)
        arr[i-1] = arr[i];
    arr[length-1] = temp;
    cout<<"The rotataed array is : ";
    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";
}
/*
The rotataed array is : 2 3 4 5 1
*/