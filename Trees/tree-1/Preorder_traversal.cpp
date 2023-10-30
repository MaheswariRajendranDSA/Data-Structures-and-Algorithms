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
void preorder(Node* node){
    if(node == NULL)
    return;

    cout<<node->data;
    preorder(node->left);
    preorder(node->right);
}
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right= new Node(5);
    cout<<"Preorder traversal is:";
    preorder(root);
    return 0;
}

/*
left->right->root
Postorder traversal is:24531
*/