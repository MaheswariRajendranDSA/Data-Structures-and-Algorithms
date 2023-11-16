#include<bits/stdc++.h>
using namespace std;

bool possible ( vector<int> &arr, int days, int M, int K){
    int cnt = 0, possibleBouquest;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=days)
        {
            cnt++;
        }
        else{
            possibleBouquest = cnt/K;
            cnt = 0;
        }
    }
    possibleBouquest+= cnt/K;
    if(possibleBouquest >= M) return true;
    else
    return false;
}
int findMinimumDays(vector<int> &arr, int M, int K){
    long long val = M * 1LL * K *1LL;
    if(val>arr.size()) return -1;

    int mini = INT_MAX, maxi = INT_MIN;

    for(int i = 0;i<arr.size();i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }   
    int low = mini, high = maxi;

    while(low<=high){
        int mid = (low+high)/2;
        if(possible(arr, mid, M, K)){
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return low;
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int noOfBouquets = 2, adjacentBouquets = 3;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int hrs = findMinimumDays(arr, noOfBouquets, adjacentBouquets);
    cout<<"The Minimum days to make M bouquets is: "<<hrs;
    return 0;
}
/*
The Minimum days to make M bouquets is: 12
*/