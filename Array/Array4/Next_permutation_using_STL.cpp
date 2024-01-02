#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3, 1, 2, 0, 0, 0, 0};
    next_permutation(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    return 0;
}
/*
3 2 0 0 0 0 1
*/