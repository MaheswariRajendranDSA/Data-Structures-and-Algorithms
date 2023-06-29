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
        queue <int> q;
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    for(auto it: topo)
    	cout<<it<<" ";
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
4 5 0 2 3 1
*/