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
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    cout<<findLomgestCommonSubsequence(strlen-1, tarlen-1, str, tar);
    return 0;
}
/*
IP
acd
ced
OP
2
*/