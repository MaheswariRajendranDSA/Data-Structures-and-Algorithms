#include<bits/stdc++.h>
using namespace std;

void dfs(int start, int vis[], vector<int>adjlist[], stack<int>&st)
{
    vis[start]=1;
    for(auto it : adjlist[start])
    {
        if(!vis[it])
        {
            dfs(it, vis, adjlist, st);
        }
    }
    st.push(start);
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>adjlist[n];
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
    }

    int vis[n] = {0};
    stack <int> st;
    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i, vis, adjlist, st);
        }
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}

/*
IP
6 6
5 0
4 0
5 2
2 3
3 1
4 1
OP
5 4 2 3 1 0
*/