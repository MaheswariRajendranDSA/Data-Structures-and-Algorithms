#include<bits/stdc++.h>
using namespace std;

vector<int> dijsktra_set(vector<vector<int>>adj[], int N, int src)
{
    set<pair<int,int>> st;
    vector<int> dist(N,1e9);
    st.insert({0,src});
    dist[src]=0;
    while(!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for(auto it : adj[node])
        {
            int edgeWeight = it[1];
            int curNode = it[0];
            if(dis + edgeWeight < dist[curNode])
            {
                if(dist[curNode]!=1e9)
                st.erase({dist[curNode], curNode});
                dist[curNode] = dis+edgeWeight;
                st.insert({dist[curNode], curNode});
            }
        }
    }
    return dist;
}
int main()
{
    int N=3, E=3, src=2;
    //cin>>N>>E>>src;
    vector<vector<int>>adj[N];
    vector<int> v1{1,1}, v2{2,6}, v3{2,3}, v4{0,1}, v5{1,3}, v6{0,6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);
    vector<int> res= dijsktra_set(adj, N, src);
    for(int i=0;i<N;i++)
    cout<<res[i]<<" ";
    cout<<"\n";
    return 0;
}

/*
OP
4 3 0 
*/