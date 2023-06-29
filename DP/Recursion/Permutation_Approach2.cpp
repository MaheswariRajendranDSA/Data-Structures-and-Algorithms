#include<bits/stdc++.h>
using namespace std;

void findPermutation2(int index, int num, vector<int>&arr, vector<vector<int>>&ans)
{
    if(index==num)
    {
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<num;i++)
    {
        swap(arr[index],arr[i]);
        findPermutation2(index+1, num, arr, ans);
        swap(arr[index],arr[i]);
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
    findPermutation2(0, num, arr, ans);
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
3 2 1
3 1 2
*/