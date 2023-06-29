#include<bits/stdc++.h>
using namespace std;

bool findWildCardMatching(int strlen, int tarlen, string str, string tar)
{
    if(strlen<0&&tarlen<0)
    return true;
    if(strlen<0&&tarlen>=0)
    return false;
    if(strlen>=0&&tarlen<0)
    {
        for(int ii=0;ii<=strlen;ii++)
        {
            if(str[strlen]!='*')
            return false;
        }
        return true;
    } 

    if(str[strlen]==tar[tarlen]||str[strlen]=='?')
    return findWildCardMatching(strlen-1, tarlen-1, str, tar);
    if(str[strlen]=='*')
    return findWildCardMatching(strlen-1, tarlen, str, tar)||findWildCardMatching(strlen, tarlen-1, str, tar);
    return false;
}
int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    bool res=findWildCardMatching(strlen-1, tarlen-1, str, tar);
    if(res)
    cout<<"True"<<"\n";
    else
    cout<<"False"<<"\n";
    return 0;
}

/*
IP
ab*cd
abdefcd
OP
True
*/