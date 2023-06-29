#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    while(start<=end)
    {
        if(str[start++]!=str[end--])
        return false;
    }
    return true;
}
void findPalindromePartition(int index, int num, string str, vector<string>&ds, vector<vector<string>>&ans)
{
    if(index==str.size())
    {
        ans.push_back(ds);
        return;
    }
    for(int i=index;i<num;i++)
    {
        if(isPalindrome(str, index, i))
        {
            ds.push_back(str.substr(index, i-index+1));
            findPalindromePartition(i+1, num, str, ds, ans);
            ds.pop_back();
        }
    }
}

int main()
{
    string str;
    cin>>str;
    vector<vector<string>>ans;
    vector<string>ds;
    int n=str.length();
    findPalindromePartition(0, n, str, ds, ans);
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
aabb
OP
a a b b
a a bb
aa b b
aa bb
*/
