#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, m;
    cin>>N>>m;
    vector<int>adj[N];
    vector<pair<int, int>> prerequisite;
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        prerequisite.push_back(make_pair(u, v));
    }
    for(auto it : prerequisite)
    {
        //int u = prerequisite[i].first;
        //int v = prerequisite[i].second;
        adj[it.first].push_back(it.second);
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
	    vector<int>topo;
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
	    if(topo.size()==N)
        cout<<"true"<<"\n";
        else
        cout<<"false"<<"\n";
	}

/*
IP
4 3
1 0    
2 1
3 2
OP
true
IP
4 4
0 1
3 2
1 3
3 0
OP
false
*/