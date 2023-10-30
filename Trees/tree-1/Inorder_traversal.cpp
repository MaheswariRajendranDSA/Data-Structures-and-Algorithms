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
void inorder(Node* node){
    if(node == NULL)
    return;

    inorder(node->left);
    cout<<node->data;
    inorder(node->right);
}
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout<<"Inorder traversal is:";
    inorder(root);
    return 0;
}

/*
left->root->right
Inorder traversal is:213
*/