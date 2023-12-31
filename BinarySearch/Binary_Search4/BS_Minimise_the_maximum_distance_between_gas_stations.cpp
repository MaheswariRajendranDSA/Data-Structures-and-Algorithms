#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i], 1});
    }
    for(int gasStations = 1; gasStations<=k; gasStations++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd] ++;
        long double miDiff = arr[secInd+1] - arr[secInd];
        long double newSecLen = miDiff/(long double)(howMany[secInd]+1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout<<"The answer is "<<ans;
    return 0;
}

/*
The answer is 0.5
*/