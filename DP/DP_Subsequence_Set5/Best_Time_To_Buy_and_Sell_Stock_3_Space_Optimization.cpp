#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];
    vector<vector<int>>front(2, vector<int>(3, 0));
    vector<vector<int>>cur(2, vector<int>(3, 0));
    for(int ind=num-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=2;cap++)
            {
                if(buy==1)
                cur[buy][cap]=max(-price[ind]+front[0][cap], 0+front[1][cap]);
                else
                cur[buy][cap]=max(price[ind]+front[1][cap-1], 0+front[0][cap]);
            }
        }
        front=cur;
    }
    cout<<front[1][2]<<"\n";
    return 0;
}

/*
IP
9
3 3 5 0 0 0 3 1 4
OP
6
*/