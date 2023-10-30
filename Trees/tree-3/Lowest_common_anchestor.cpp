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

Node * LowAnchestor(Node* node, Node* p, Node* q){
    if(node == NULL || node == p || node== q)
        return node;
    Node * left = LowAnchestor(node->left, p, q);
    Node * right = LowAnchestor(node->right, p, q);
    
    if(left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return node;
}

};
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    cout<<"Lowest common anchestor:"<<"\n";
    Solution obj;
    Node* node = obj.LowAnchestor(root, root->right->left, root->right->right);
    cout<<node->data;
        return 0;
    }
/*
Lowest common anchestor:
3
*/