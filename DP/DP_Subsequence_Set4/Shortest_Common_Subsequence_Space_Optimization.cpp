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
    cout<<strlen+tarlen-prev[tarlen]<<"\n";
    int i=strlen, j=tarlen;
    string ans="";
    while(i>0&&j>0)
    {
        if(str[i-1]==tar[j-1])
        {
            ans+=str[i-1];
            i--;
            j--;
        }
        else if(prev[j]>cur[j-1])
        {
            ans+=str[i-1];
            i--;
        }
        else
        {
            ans+=tar[j-1];
            j--;
        }
    }
    while(i>0)
    {
        ans+=str[i-1];
        i--;
    }

  while(j>0)
    {
        ans+=tar[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
    return 0;
}

/*
IP
abcde
abn
OP
6
abcden
*/