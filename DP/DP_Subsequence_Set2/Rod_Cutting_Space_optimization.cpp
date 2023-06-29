#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];
     
    vector<int>prev(num+1, 0), cur(num+1, 0);

    for(int i=0;i<=num;i++)
    prev[i]=(i*price[0]);

    for(int ind=1;ind<num;ind++)
    {
        for(int len=0;len<=num;len++)
            {
                int nottake=prev[len];

                int take=-1e9;
                int rodlength=ind+1;
                if(rodlength<=len)
                take=cur[len-rodlength]+price[ind];

                cur[len]=max(take, nottake);
            }
            prev=cur;
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