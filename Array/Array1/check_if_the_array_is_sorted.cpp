#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {10, 3, 4, 12, 87};
    int flag = 1;
    int length = arr.size();
    for(int i = 1; i < length; i ++){
        if(arr[i-1] < arr[i]){
        }
        else 
        {
            flag = 0;
            cout<<"the array is not sorted";
            break;
        }
        }
    if(flag)
    cout<<"the array is sorted";
    return 0;
}

/*
the array is not sorted
*/