#include<bits/stdc++.h>
using namespace std;

void findCombinationSum2(int index, int target, int num, vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans)
{
    if(target==0)
    {
        ans.push_back(ds);
        return;
    }
    for(int i=index;i<num;i++)
    {
        if(i>index&&arr[i]==arr[i-1])
        continue;
        ds.push_back(arr[i]);
        findCombinationSum2(i+1, target-arr[i], num, arr, ds, ans);
        ds.pop_back();
    }
}
int main()
{
    int num,target;
    cin>>num>>target;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>ds;
    vector<vector<int>>ans;
    findCombinationSum2(0, target, num, arr, ds, ans);
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
5 4
1 1 1 2 2
OP
1 1 2
2 2
*/