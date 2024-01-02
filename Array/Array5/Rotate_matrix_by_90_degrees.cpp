#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix, int n, int m) {
    for(int i =0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i =0;i<n;i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = matrix.size();
    int m = matrix[0].size();
    rotateMatrix(matrix, n, m);

    cout << "The rotated matrix is: "<<"\n";
    for (auto it : matrix) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
The rotated matrix is: 
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4
*/