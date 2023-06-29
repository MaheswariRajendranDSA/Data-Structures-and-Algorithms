#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    public:
    vector<int> size, parent;
    disjointSet(int n){
    size.resize(n+1, 1);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    parent[i] = i;
    }
    int findUpar(int node)
    {
        if(node == parent[node])
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBysize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v)
        return;
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
         else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

vector<vector<string>> accountMerge (vector<vector<string>> &accounts)
{
    int n = accounts.size();
    disjointSet ds(n);
    sort(accounts.begin(), accounts.end());
    unordered_map<string, int> mapMailNode;

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<accounts[i].size();j++)
        {
            string mail = accounts[i][j];
            if(mapMailNode.find(mail) ==  mapMailNode.end())
            {
                mapMailNode[mail] = i;
            }
            else{
                ds.unionBysize(i, mapMailNode[mail]);
            }
        }
    }

    vector<string> mergedMail[n];

    for(auto it: mapMailNode)
    {
        string mail = it.first;
        int node = ds.findUpar(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i=0;i<n;i++)
    {
        if(mergedMail[i].size() ==0)
        continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it : mergedMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
    int n;
    cin>>n;
    vector<vector<string>> accounts ;
    for(int i=0;i<n;i++)
    {
        vector<string> temp;
        int x;
        cin>>x;
        for(int j=0;j<x;j++)
        {
            string s;
            cin>>s;
            temp.push_back(s);
        }
        accounts.push_back(temp);
    }
    /*= {{"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };*/

    vector<vector<string>> ans = accountMerge(accounts);
    for(auto acc : ans)
    {
        cout<<acc[0]<<":";
        int size = acc.size();
        for(int i=1;i<size;i++)
        {
            cout<<acc[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/*
OP
John:j1@com j2@com j3@com j5@com 
John:j4@com
Mary:m1@com
Raj:r1@com r2@com r3@com
*/