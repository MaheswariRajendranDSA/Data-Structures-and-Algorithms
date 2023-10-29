#include<bits/stdc++.h>
using namespace std;

void findSubsetSumOne(int index, int sum, int num, vector<int>&ans, vector<int>&arr)
{
    if(index==num)
    {
        ans.push_back(sum);
        return;
    }
     findSubsetSumOne(index+1, sum+arr[index], num, ans, arr); //include
     findSubsetSumOne(index+1, sum, num, ans, arr);//not include
}
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>ans;
    findSubsetSumOne(0, 0, num, ans, arr);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
/*
IP
3
3 1 2 
OP
6 4 5 3 3 1 2 0*/