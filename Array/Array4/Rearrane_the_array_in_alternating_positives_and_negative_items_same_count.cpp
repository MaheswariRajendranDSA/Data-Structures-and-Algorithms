#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int n = arr.size();
    int k = 6;
    int left = 0, right = 0;
    long long sum =  arr[0];
    int maxLen = 0;

    while(right < n){
        while(left<=right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
        right ++;
        if(right < n){
            sum += arr[right];
        }
    }
    cout<<"The longest subarray sum is :"<<maxLen;
}
/*
The longest subarray sum is :4
*/