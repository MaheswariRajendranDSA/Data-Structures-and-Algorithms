#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];
     
    vector<int>prev(num+1, 0);

    for(int i=0;i<=num;i++)
    prev[i]=(i*price[0]);

    for(int ind=1;ind<num;ind++)
    {
        for(int len=num;len>=0;len--)
            {
                int nottake=prev[len];

                int take=-1e9;
                int rodlength=ind+1;
                if(rodlength<=len)
                take=prev[len-rodlength]+price[ind];

                prev[len]=max(take, nottake)
            }
    }
    cout<<prev[num];
    return 0;
}


/*
IP
5
2 5 7 8 10
OP
12
*/