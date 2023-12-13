#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {10, 3, 4, 12, 87};
    int length = arr.size();
    int max_element = -1;
    for(int i = 0; i < length; i ++){
        if(arr[i] > max_element){
            max_element = arr[i];
        }
    }
    cout<<"The largest element in array is "<<max_element;
    return 0;
}

/*
The largest element in array is 87
*/