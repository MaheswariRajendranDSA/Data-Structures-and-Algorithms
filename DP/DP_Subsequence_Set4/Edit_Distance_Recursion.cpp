#include<bits/stdc++.h>
using namespace std;

int findEditDistance(int strlen, int tarlen, string &str, string &tar)
{
    if(strlen<0)
    return tarlen+1;

    if(tarlen<0)
    return strlen+1;
    
    if(str[strlen]==tar[tarlen])
    return findEditDistance(strlen-1, tarlen-1, str, tar);

    return 1+min({
        findEditDistance(strlen, tarlen-1, str, tar),
        findEditDistance(strlen-1, tarlen, str, tar),
        findEditDistance(strlen-1, tarlen-1, str, tar)});
}
int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    int res=findEditDistance(strlen-1, tarlen-1, str, tar);
    cout<<res<<"\n";
    return 0;
}

/*
IP
horse
ros
OP
3
*/