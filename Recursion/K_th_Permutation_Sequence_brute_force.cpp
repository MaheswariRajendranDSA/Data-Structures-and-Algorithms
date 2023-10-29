#include<bits/stdc++.h>
using namespace std;

void Permutation(string res, vector<string>&ans, int index)
{
    if(index==res.size())
    {
        ans.push_back(res);
        return;
    }
    for(int i=index;i<res.size();i++)
    {
        swap(res[index], res[i]);
        Permutation(res, ans, index+1);
        swap(res[index], res[i]);
    }
}
string getPermutation(int n, int k)
{
    string res;
    vector<string>ans;
    for(int i=1;i<=n;i++)
    res.push_back(i+'0');
    Permutation(res, ans, 0);
    sort(ans.begin(),ans.end());
    auto it=ans.begin()+k-1;
    return *it;
}
int main()
{
    int n, k;
    cin>>n>>k;
    string ans=getPermutation(n, k);
    cout<<ans<<"\n";
    return 0;
}
/*
IP
3 3
OP
213
*/