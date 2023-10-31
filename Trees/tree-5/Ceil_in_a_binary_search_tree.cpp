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
int ceilBST(Node *root, int val){
    int ceil = -1;
    while(root){
        if(root->data ==  val){
            ceil= root->data;
            return ceil;
        }
        else if (val > root -> data)
        {
            root = root->right;
        }
        else {
            ceil  = root->data;
            root= root->left;
        }
    }
    return ceil;
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
    cout<<"Ceil in binary search tree:"<<"\n";
    Solution obj;
    int val;
    cin>>val;
    int target = obj.ceilBST(root, val);
    cout<<target;
    return 0;
}
/*
Ceil in binary search tree:
9
10
*/