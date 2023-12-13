#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {3, 3, 4, 4, 5};
    int length = arr.size();
    int i = 0;
    for(int j = 1; j < length; j ++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
        }
    cout<<"The unique numbers in array is "<<i+1;
    return 0;
    }

/*
The largest element in array is 87
*/