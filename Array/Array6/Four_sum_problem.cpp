#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findFourSum(vector<int> &arr, int n){
     set<vector<int>> st;
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long> hashset;
            for(int k=j+1;k<n;k++){
                int remaining = -(arr[i]+arr[j+arr[k]]);
                if(hashset.find(remaining)!=hashset.end()){
                    vector<int>temp = {arr[i],arr[j], arr[k], remaining};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main(){
    vector<int> arr = {-1, 0, 1, 0, -2, 4};
    int n = arr.size();
    vector<vector<int>> res = findFourSum(arr, n);
    cout<<"The quadrant element is: "<<"\n";
    for(auto it:res){
        for(int i : it)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
The quadrant element is: 
-1 0 0 1
*/