#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<int>prev(tarlen+1, 0), cur(tarlen+1, 0);
    
    for(int j=0;j<=tarlen;j++)
    prev[j]=j;

    for(int i=1;i<=strlen;i++)
    {
        cur[0]=i;
        for(int j=1;j<=tarlen;j++)
        {
            if(str[i-1]==tar[j-1])
            {
                cur[j]=prev[j-1];
            }
            else
            cur[j]=1+min({cur[j-1], prev[j], prev[j-1]});
        }
        prev=cur;
    }
    cout<<prev[tarlen]<<"\n";
    return 0;
}

/*
IP
horse
ros
OP
3
*/