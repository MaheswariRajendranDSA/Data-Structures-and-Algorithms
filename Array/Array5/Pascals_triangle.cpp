#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row){
    long long ans = 1;
    vector<int>ansRow;
    ansRow.push_back(1);

    for(int col = 1; col<row; col++)
    {
        ans = ans * (row - col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalsTriangle(int n){
    vector<vector<int>> ans;
    for(int row = 1;row<=n;row++)
        ans.push_back(generateRow(row));
    return ans;
}
int main(){
    int n = 5;
    vector<vector<int>> ans = pascalsTriangle(n);
    for(auto i : ans){
        for(int it: i)
            cout<<it<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/