#include<bits/stdc++.h>
using namespace std;

int findDistinctSubsequence(int strlen, int tarlen, string &str, string &tar)
{
    if(tarlen<0)
    return 1;
    if(strlen<0)
    return 0;

    if(str[strlen]==tar[tarlen])
    {
        return findDistinctSubsequence(strlen-1, tarlen-1, str, tar)+
            findDistinctSubsequence(strlen-1, tarlen, str, tar);
    }
    return findDistinctSubsequence(strlen-1, tarlen, str, tar);
}
int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    int res=findDistinctSubsequence(strlen-1, tarlen-1, str, tar);
    cout<<res<<"\n";
    return 0;
}

/*
IP
babgbag
bag
OP
5*/