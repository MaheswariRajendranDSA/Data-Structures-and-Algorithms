#include<bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> &arr){
    int n = arr.size();
    int pre =1 , suf = 1;
    int ans = INT_MIN;
    for(int i = 0 ; i<n;i++){
        if(pre ==0) pre = 1;
        if(suf==0) suf =1;
        pre*= arr[i];
        suf*= arr[n-i-1];
        ans = max({ans, pre, suf});
    }
    return ans;
}
int main(){
    vector<int> arr= {1,2, -3, 0, -4, -5};
    cout<<"The maximum product subarray is: ";
    cout<<maxProductSubarray(arr);
    return 0;
}

/*
The maximum product subarray is:
20
*/