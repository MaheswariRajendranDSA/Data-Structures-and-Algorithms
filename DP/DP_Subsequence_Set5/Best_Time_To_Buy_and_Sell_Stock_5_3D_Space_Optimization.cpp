#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];

    vector<int>front2 (2, 0), front1(2, 0), cur(2, 0);

                
    for(int i=num-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
                if(buy)
                {
                    profit=max(-arr[i]+front1[0], 0+front1[1]);
                }
                else
                {
                    profit=max(arr[i]+front2[1], 0+front1[0]);
                }
            cur[buy]=profit;
        }
        front2=front1;
        front1=cur;
    }
    cout<<front1[1];
}

/*
IP
5
4 9 0 4 10
OP
11
*/
