#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    
    vector<double>prev(tarlen+1, 0);

    prev[0]=1;

    for(int i=1;i<=strlen;i++)
    {
        for(int j=tarlen;j>=0;j--)
        {
            if(str[i-1]==tar[j-1])
            {
            prev[j]=prev[j-1]+prev[j];
            }
            else
            {
            prev[j]=prev[j];
            }
        }
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