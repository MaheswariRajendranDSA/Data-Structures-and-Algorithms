#include<bits/stdc++.h>
using namespace std;

int findCountNoOfSubarrays(vector<int> &arr, int n, int k){
    int xr = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    int count = 0;
    for(int i = 0; i<n;i++){
        xr = xr^arr[i];
        int remaining = xr ^ k;
        if(mpp.find(remaining)!=mpp.end()){
            count+=mpp[remaining];
        }
        mpp[xr]++;
    }
    return count;
}
int main(){
    vector<int> arr = {4, 2, 2, 6, 4};
    int n = arr.size();
    int k = 6;
    int res = findCountNoOfSubarrays(arr, n, k);
    cout<<res<<"\n";
    return 0;
}

/*
4
*/