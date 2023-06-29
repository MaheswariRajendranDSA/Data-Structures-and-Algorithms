#include<bits/stdc++.h>
using namespace std;

int minimumMultiplication(int start, int end, int n, vector<int> &arr)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int>dist(100000, 1e9);
    dist[start]=0;
    int mod = 100000;
    while(!q.empty())
    {
        int node = q.front().first;
        int stops = q.front().second;
        q.pop();

        for(auto it : arr)
        {
            int num = (it*node)%mod;

            if(stops+1 < dist[num])
            {
                dist[num]= stops+1;
                if(num == end) return stops +1;
                q.push({num, stops+1});
            }
        }
    }
    return -1;
}
int main()
{
    int start, end, n;
    cin>>start>>end>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int ans = minimumMultiplication(start, end, n, arr);
    cout<<ans<<"\n";
    return 0;
}

/*
IP
3 30 3
2 5 7
OP
2
IP
7 66175 3
3 4 65
OP
4
*/