// everything on the right should be less than current
#include<bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> &arr, int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    int n = arr.size();
    vector<int> ar = findLeaders(arr, n);
    for(int i = 0; i < ar.size(); i++)
        cout<<ar[i]<<" ";
    return 0;
}
/*
The leaders are: 6 12 22 
*/