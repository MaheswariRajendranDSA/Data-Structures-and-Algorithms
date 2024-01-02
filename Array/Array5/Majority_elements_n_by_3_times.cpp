#include<bits/stdc++.h>
using namespace std;

vector<int> findMajorityElement(vector<int> &arr, int n){
    int cnt1= 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
    for(int i = 0; i<arr.size(); i++){
        if(cnt1 == 0 && ele2!=arr[i]){
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && ele1!=arr[i]){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if (ele1 == arr[i]) cnt1++;
        else if (ele2 == arr[i]) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1 =0, cnt2 =0;
    int mini = n/3+1;
    for(int i = 0;i<n;i++)
    {
        if(ele1 ==arr[i]) cnt1++;
        if(ele2 ==arr[i]) cnt2++;
    }
    if(cnt1 >= mini)
    ls.push_back(ele1);
     if(cnt2 >= mini)
    ls.push_back(ele2);
    sort(ls.begin(), ls.end());
    return ls;
}
int main(){
    vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = arr.size();
    vector<int> res = findMajorityElement(arr, n);
    cout<<"The majority element is: ";
    for(int i = 0; i<2; i++)
    cout<<res[i]<<" ";
    return 0;
}

/*
The majority element is: 1 2
*/