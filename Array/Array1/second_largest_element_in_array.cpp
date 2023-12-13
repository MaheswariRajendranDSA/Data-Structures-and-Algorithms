#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {10, 3, 4, 12, 87};
    int largest = INT_MIN;
    int secondlargest = INT_MIN;
    int length = arr.size();
    for(int i = 0; i < length; i ++){
        if(arr[i] > largest){
            secondlargest = largest;
            largest = arr[i];
        }
        else if(arr[i] != largest && arr[i] > secondlargest){
            secondlargest = arr[i];
        }
    }
    cout<<"The second largest element in array is "<<secondlargest;
    return 0;
}

/*
The second largest element in array is 12
*/