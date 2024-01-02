#include<bits/stdc++.h>
using namespace std;

int findCountSubsum(vector<int> &arr, int n, int k){
    map<int, int> mpp;    mpp[0]=1;
    int preSum = 0, cnt = 0;
    for(int i = 0; i<n;i++)
    {
        preSum += arr[i];
        int remaining = preSum - k;
        cnt += mpp[remaining];
        mpp[preSum]+=1;
    }
    return cnt;
}
int main(){
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int n = arr.size();
    int k = 3;
    int res = findCountSubsum(arr, n, k);
    cout<<"The count of subarray sum is : "<<res;
    return 0;
}

/*
The count of subarray sum is : 8
*/