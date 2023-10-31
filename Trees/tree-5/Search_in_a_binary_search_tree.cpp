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
class Solution {
public:
Node *searchBST(Node *root, int val){
    while(root != NULL && root->data != val)
    {
        root = val < root->data ? root->left : root -> right;
    }
    return root;
}
};
int main(){
      Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    //root->right->left = new Node(2);
    root->left->left= new Node(1);
    root->left->right= new Node(6);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(7);
    root->right->right= new Node(14);
    root->right->right->left= new Node(13);
    cout<<"Search in a binary search tree:"<<"\n";
    Solution obj;
    int val;
    cin>>val;
    Node* target = obj.searchBST(root, val);
    cout<<target->data;
    return 0;
}
/*
Search in a binary search tree:
4
4
*/