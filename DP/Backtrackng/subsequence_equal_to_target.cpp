#include<bits/stdc++.h>
using namespace std;

void find_target_subsequences(int index, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds)
{
    if(index==arr.size()-1)
    {
        if(target==0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if(target-arr[index]>=0)
    {
    ds.push_back(arr[index]);
    find_target_subsequences(index+1,target-arr[index], arr, ans, ds); //include 
    ds.pop_back();
    }
    find_target_subsequences(index+1,target, arr, ans, ds);   // not include
}
int main()
{
    int num,target;
    cin>>num>>target;
    vector<int> arr(num+1);
    vector<int> ds;
    vector<vector<int>> ans;
    for(int i=0;i<num;i++)
    cin>>arr[i];
    find_target_subsequences(0,target, arr, ans, ds);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
/*
IP
4 10
5 5 4 6
OP
5 5
4 6
*/