#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 4, 5};
    int n = arr.size();
    int xor1 =0, xor2 =0;
    for(int i = 1; i <=n; i ++){
        xor1 = xor1 ^ (i);
    }
    for(int i = 0; i < n-1; i ++){
        xor2 = xor2 ^ arr[i];
    }
    //xor1 = xor1 ^ n;
     int ans = xor1 ^ xor2;
     cout<<"The missing number in an array is "<<ans;
}
/*
The missing number in an array is 3
*/