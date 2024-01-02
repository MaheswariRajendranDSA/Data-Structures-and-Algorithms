#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findMergeOverlap(vector<vector<int>> &arr){
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i =0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, 
    {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    vector<vector<int>> ans = findMergeOverlap(arr);
    cout<<"The merged sub intervals are: "<<"\n";
    for(auto it:ans){
            cout<<it[0]<<" "<<it[1]<<" ";
            cout<<"\n";
    }
    return 0;
}

/*
The merged sub intervals are:
1 6 
8 11
15 18
*/