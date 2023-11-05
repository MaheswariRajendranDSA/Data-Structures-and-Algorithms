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
Node *lowAnchestor(Node *root, Node *p, Node *q)
{
    if(root == NULL ) return root;
    int cur = root->data;
    if(cur < p->data && cur < q->data)
    {
        return lowAnchestor(root->right, p, q);
    }
    if(cur > p->data && cur > q->data)
    {
        return lowAnchestor(root->left, p, q);
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
    cout<<"Lowest Common anchestor in BST:"<<"\n";
    Solution obj;
    Node *target = obj.lowAnchestor(root, root->left->left, root->left->right);
    cout<<target->data;
   return 0;
}
/*
Lowest Common anchestor in BST:
3
*/