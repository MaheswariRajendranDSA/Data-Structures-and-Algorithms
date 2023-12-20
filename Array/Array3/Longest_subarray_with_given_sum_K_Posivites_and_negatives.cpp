#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 0, 0, 0, 6, 4, 2, 3};
    int n = arr.size();
    int k = 6;
    map<long long , int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i< n;i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(rem) == preSumMap.end()){
            preSumMap[rem] = i;
        }
    }
    cout<<"The longest subarray sum is :"<<maxLen;
    return 0;
}
/*
The longest subarray sum is :6
*/