#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplet(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i =0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum>0)
                k--;
            else if(sum<0)
                j++;
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]== arr[j-1])j++;
                while(j<k && arr[k] == arr[k-1]) k--;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> res = findTriplet(arr, n);
    cout<<"The Triplet element is: "<<"\n";
    for(auto it:res){
        for(int i : it)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
The Triplet element is: 
-1 -1 2
-1 0 1
*/