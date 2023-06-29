#include<bits/stdc++.h>
using namespace std;

vector<int> toposort (int N ,vector<int> adj[])
{
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
        return topo;
}
string findOrder(string dict[], int N, int K)
{
    vector<int>adj[K];

    for(int i=0;i<N-1;i++)
    {
        string s1 = dict[i];
        string s2 = dict[i+1];
        for(int j=0;j<K;j++)
        {
            if(s1[j] != s2[j])
            adj[s1[j]-'a'].push_back(s2[j]-'a');
            break;
        }
    }
    vector<int>topo = toposort(K, adj);
    string ans = "";
    for(auto it : topo)
    {
        ans+=char(it+'a');
    }
    return ans;
}
int main()
{
    int N, K;
    cin>>N>>K;
    string dict[N];
    for(int i=0;i<N;i++)
    cin>>dict[i];
    string ans = findOrder(dict, N, K);
    for(auto ch : ans)
    {
        cout<<ch<<' ';
    }
    cout<<"\n";
    return 0;
}

/*
IP
5 4
baa 
abcd
abca
cab
cad
OP
b d a c 
*/