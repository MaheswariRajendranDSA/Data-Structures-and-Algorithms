#include<bits/stdc++.h>
using namespace std;

void findSubsetSum2(int index, int num, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds)
{
    //if(index<=num)
    ans.push_back(ds);
    for(int i=index;i<num;i++)
    {
        if(i!=index&&arr[i]==arr[i-1])
        continue;
        ds.push_back(arr[i]);
        findSubsetSum2(i+1, num, arr, ans, ds);
        ds.pop_back();
    }
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<vector<int>>ans;
    vector<int>ds;
    findSubsetSum2(0, num, arr, ans, ds);
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
3
1 2 2
OP
1
1 2
1 2 2
2
2 2*/