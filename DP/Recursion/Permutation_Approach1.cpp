#include<bits/stdc++.h>
using namespace std;

void findPermutation1(int num, vector<int>&arr, vector<int>&freq, vector<int>&ds, vector<vector<int>>&ans)
{
    if(ds.size()==num)
    {
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<num;i++)
    {
        if(freq[i]==0)
        {
            ds.push_back(arr[i]);
            freq[i]=1;
            findPermutation1(num,arr, freq, ds, ans);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    vector<int>freq(num,0);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>ds;
    vector<vector<int>>ans;
    findPermutation1(num, arr, freq, ds, ans);
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
1 2 3
OP
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/