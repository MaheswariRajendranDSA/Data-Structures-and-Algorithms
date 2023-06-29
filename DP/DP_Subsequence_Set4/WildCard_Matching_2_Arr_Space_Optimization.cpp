#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<bool>prev(tarlen+1, false), cur(tarlen+1, false);
    prev[0]=true;
    for(int j=1;j<=tarlen;j++)
    prev[j]=false;

    for(int i=1;i<=strlen;i++)
    {
        int flag=true;
        for(int ii=1;ii<=i;ii++)
        {
            if(str[ii-1]!='*')
            {
                flag=false;
                break;
            }
        }
        cur[0]=flag;
        for(int j=1;j<=tarlen;j++)
        {
            if(str[i-1]==tar[j-1]||str[i-1]=='?')
            cur[j]=prev[j-1];
            else if(str[i-1]=='*')
            cur[j]=prev[j]||cur[j-1];
            else
            cur[j]=false;
        }
        prev=cur;
    }
    if(prev[tarlen])
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