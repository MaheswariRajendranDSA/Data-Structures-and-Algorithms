#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
     Node* left;
     Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout<<"created binary representaion of tree in c++";
    return 0;
}