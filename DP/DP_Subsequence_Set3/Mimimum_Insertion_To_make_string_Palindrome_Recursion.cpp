#include<bits/stdc++.h>
using namespace std;

int findLomgestCommonSubsequence(int strlen, int tarlen, string str, string tar)
{
    if(strlen<0 || tarlen<0)
    return 0;

    if(str[strlen]==tar[tarlen])
    {
        return 1+findLomgestCommonSubsequence(strlen-1, tarlen-1, str, tar);
    }

    return max(findLomgestCommonSubsequence(strlen, tarlen-1, str, tar),
                   findLomgestCommonSubsequence(strlen-1, tarlen, str, tar));
}
int main()
{
    string str;
    cin>>str;
    int strlen=str.size();
    string tar;
    tar=str;
    reverse(str.begin(), str.end());
    int palindrome=findLomgestCommonSubsequence(strlen-1, strlen-1, tar, str);
    int res=strlen-palindrome;
    cout<<res<<"\n";
    return 0;
}
/*
IP
codingninjas
OP
7
explanation-palindrome -ingni - palindrome remianing 12-5=7
*/