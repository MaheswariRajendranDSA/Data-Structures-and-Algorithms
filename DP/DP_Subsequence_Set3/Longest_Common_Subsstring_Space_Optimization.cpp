#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size(), tarlen=tar.size();
    vector<int>prev(tarlen+1, 0), cur(tarlen+1, 0);
    
    for(int tl=0;tl<=tarlen;tl++)
    prev[tl]=0;

    for(int sl=1;sl<=strlen;sl++)
    {
        for(int tl=1;tl<=tarlen;tl++)
        {
            if(str[sl-1]==tar[tl-1])
            cur[tl]=1+prev[tl-1];
            else
            cur[tl]=0;
        }
        prev=cur;
    }
    cout<<prev[tarlen];
    return 0;
}

/*
IP
axbcd
ambcd
OP
3
*/