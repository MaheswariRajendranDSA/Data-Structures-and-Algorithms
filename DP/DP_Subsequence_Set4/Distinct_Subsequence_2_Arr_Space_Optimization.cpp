#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    
    vector<double>prev(tarlen+1, 0), cur(tarlen+1, 0);

    prev[0]=cur[0]=1;

    for(int i=1;i<=strlen;i++)
    {
        for(int j=1;j<=tarlen;j++)
        {
            if(str[i-1]==tar[j-1])
            {
            cur[j]=prev[j-1]+prev[j];
            }
            else
            {
            cur[j]=prev[j];
            }
        }
        prev=cur;
    }
    cout<<prev[tarlen]<<"\n";
    return 0;
}

/*
IP
babgbag
bag
OP
5
*/