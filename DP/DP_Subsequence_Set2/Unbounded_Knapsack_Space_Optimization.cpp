#include<bits/stdc++.h>
using namespace std;


int main()
{
    int num, wtofbg;
    cin>>num>>wtofbg;
    vector<int>weight(num), value(num);

    for(int i=0;i<num;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<num;i++)
    {
        cin>>value[i];
    }

    vector<int>prev(wtofbg+1, 0), cur(wtofbg+1, 0);
    

    for(int i=weight[0];i<=wtofbg;i++)
    prev[i]=(int)((i/weight[0])*value[0]);

    for(int ind=1;ind<num;ind++)
    {
        for(int wt=0;wt<=wtofbg;wt++)
        {
            int nottake=prev[wt];

            int take=INT_MIN;
            if(weight[ind]<=wt)
            take=cur[wt-weight[ind]]+value[ind];

            cur[wt]=max(take, nottake);
        }
        prev=cur;
    }
    cout<<prev[wtofbg]<<"\n";
    return 0;
}

/*
IP
3 10
2 4 6
5 11 13
OP
27
*/