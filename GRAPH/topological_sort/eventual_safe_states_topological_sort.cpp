#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, m;
    cin>>N>>m;
    vector<int>adj[N];
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>adjrev[N];
    for(int i=0;i<N;i++)
    {
        for(auto it : adj[i])
        {
            adjrev[it].push_back(i);
        }
    }
        queue <int> q;
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adjrev[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> safe_nodes;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        safe_nodes.push_back(node);
	        for(auto it : adjrev[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }

        sort(safe_nodes.begin(), safe_nodes.end());
	    for(auto it : safe_nodes)
        cout<<it<<" ";
	}

/*
IP
8 8
0 1
1 3
3 0
0 2
1 2
2 5
4 5
7 1
OP
2 4 5 6
*/