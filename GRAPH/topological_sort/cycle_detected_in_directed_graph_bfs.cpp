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
	    int cnt=0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++;
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt==N)
        cout<<"false"<<"\n";
        else
        cout<<"true"<<"\n";
	}

/*
IP
3 2
0 1
1 2
op
1
IP
6 6
5 0
4 0
5 2
2 3
3 1
4 1
OP
0
*/