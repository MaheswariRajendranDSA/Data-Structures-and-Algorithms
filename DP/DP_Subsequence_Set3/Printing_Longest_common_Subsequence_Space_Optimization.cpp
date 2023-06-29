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
            cur[tl]=max(prev[tl],cur[tl-1]);
        }
        prev=cur;
    }
    
    int length=prev[tarlen];

    int i=strlen, j=tarlen;
    string ans="";
    int index=length-1;
    for(int i=0;i<length;i++)
    ans+='#';

    while(i>0&&j>0)
    {
        if(str[i-1]==tar[j-1])
        {
            ans[index]=str[i-1];
            i--;
            j--;
            index--;
        }
        else if(prev[j]>cur[j-1])
        {
            i--;
        }
        else
        j--;
    }
    cout<<ans;
    return 0;
}

/*
IP
abcd
abd
OP
abd
*/