#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<vector<int>>points(num, vector<int>(4));
    vector<int>prev(5);

    for(int i=0;i<num;i++)
    {
        for(int j=0;j<3;j++)
        {
             cin>>points[i][j];
        }
    }
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max({points[0][0],points[0][1],points[0][2]});

    for(int days=1;days<num;days++)
    {
        vector<int>temp(4,0);
        for(int last=0;last<4;last++)
        {
            temp[last]=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=points[days][task]+prev[task];
                    temp[last]=max(temp[last], point);
                }
            }
        }
        prev=temp;
    }
    cout<<prev[3];
    return 0;
}
/*
IP
2
10 50 1
5 100 11
OP
110
*/