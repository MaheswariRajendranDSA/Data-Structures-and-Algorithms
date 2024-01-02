#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3, 1, -2, -5, 2, 4};
    int n = arr.size();
    vector<int> pos, neg;
    for(int i = 0; i < n; i ++){
        if(arr[i]>0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size(); i++){
            arr[i*2] = pos[i];
            arr[i*2+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i = neg.size(); i < pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else {
        for(int i = 0; i < pos.size(); i++){
            arr[i*2] = pos[i];
            arr[i*2+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i = pos.size(); i < neg.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    cout<<"The ordered array is ";
    for(int i = 0; i < n ; i ++)
        cout<<arr[i]<<" ";
}
/*
The ordered array is 3 -2 1 -5 2 4 
*/