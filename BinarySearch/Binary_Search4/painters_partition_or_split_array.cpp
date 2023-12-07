#include<bits/stdc++.h>
using namespace std;

int countPainters ( vector<int> &boards, int area){
    int painters = 1;
    int paintedArea = 0;
    for(int i=0;i<boards.size();i++)
    {
        if(paintedArea+boards[i]<=area)
        {
            paintedArea+=boards[i];
        }
        else
        {
            painters++;
            paintedArea = boards[i];
        }
    }
    return painters;
}
int findArea(vector<int> &boards, int painters){
    int n = boards.size();
    if(n<painters) return -1;
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while(low<=high){
        int mid = (low+high)/2;
        int cntPainters = countPainters(boards, mid);
        if(cntPainters>painters)
        {
            low = mid+1;
        }
        else
            high = mid - 1;
    }
    return low;
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int minimumArea = findArea(boards, painters);
    cout<<"The answer is: "<<minimumArea;
    return 0;
}
/*
The answer is: 60
*/