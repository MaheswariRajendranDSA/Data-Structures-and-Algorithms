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
int maxDepth(Node* node){
    if(node == NULL)
    return 0;

    int lh = maxDepth(node -> left);
    int rh = maxDepth(node -> right);
    return 1 + max(lh, rh);
    }
int main(){
     Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right= new Node(3);
    cout<<"Maximum Depth of binary tree is:"<<"\n";
    int res = maxDepth(root);
    cout<<res;
    return 0;
}

/*
Maximum Depth of binary tree is:
3
*/