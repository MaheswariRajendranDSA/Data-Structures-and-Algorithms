// everything on the right should be less than current
#include<bits/stdc++.h>
using namespace std;

int findConsuecutiveSequence(vector<int> &arr, int n){
    if(n==0) return 0;
    unordered_set<int> st;
    for(int i = 0; i<n;i++)
        st.insert(arr[i]);
    int longest = 1;
    for(auto it : st){
        if(st.find(it-1)==st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt+=1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> arr = {10, 12, 5, 11, 6, 34};
    int n = arr.size();
    int res = findConsuecutiveSequence(arr, n);
    cout<<"The longest consecutive sequence is: "<<res<<" ";
    return 0;
}
/*
The longest consecutive sequence is: 3 
*/