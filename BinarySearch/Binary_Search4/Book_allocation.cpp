#include<bits/stdc++.h>
using namespace std;

int countStudents ( vector<int> &books, int pages){
    int students = 1;
    int pageStudent = 0;
    for(int i=0;i<books.size();i++)
    {
        if(pageStudent+books[i]<=pages)
        {
            pageStudent+=books[i];
        }
        else
        {
            students++;
            pageStudent = books[i];
        }
    }
    return students;
}
int findPages(vector<int> &books, int students){
    int n = books.size();
    if(n<students) return -1;
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    while(low<=high){
        int mid = (low+high)/2;
        int cntStudents = countStudents(books, mid);
        if(cntStudents>students)
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
    vector<int> books = {25, 46, 28, 49, 24};
    int students = 4;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int minimumPages = findPages(books, students);
    cout<<"The minimum Pages need to allocate all students is: "<<minimumPages;
    return 0;
}
/*
The minimum Pages need to allocate all students is: 71
1/5+2/5+5/5+9/5 = 5<=6
*/