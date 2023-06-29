#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int strlen=str.size();
    string tar;
    tar=str;
    reverse(tar.begin(), tar.end());
    vector<int>prev(strlen+1, 0), cur(strlen+1, 0);
    
    for(int tl=0;tl<=strlen;tl++)
    prev[tl]=0;

    for(int sl=1;sl<=strlen;sl++)
    {
        for(int tl=1;tl<=strlen;tl++)
        {
            if(str[sl-1]==tar[tl-1])
            cur[tl]=1+prev[tl-1];
            else
            cur[tl]=max(prev[tl],cur[tl-1]);
        }
        prev=cur;
    }
    cout<<prev[strlen];
    return 0;
}

/*
IP
bbabcbcab
OP
7
*/