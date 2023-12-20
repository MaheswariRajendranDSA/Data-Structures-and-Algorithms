//Moore's voting algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
    int n = arr.size(), cnt = 0, element;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            cnt++;
            element = arr[i];
        }
        if(arr[i] == element)
            cnt ++;
        else 
            cnt--;
    }
    int cnt1 = 0;
    for(int i = 0; i < n; i ++)
        if(element == arr[i]) cnt1++;
    if(cnt1 > n/2)
    {
        cout<<"The magority element is : "<<element;
        return 0;
    }
    cout<<"There is no majority element here";
    return 0;
}
/*
The magority element is : 2
*/