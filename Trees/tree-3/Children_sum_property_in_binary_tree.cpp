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

Node* childrenSum(Node* node, Node* res){
    if(node == NULL )
        return node;

    int child = 0;

    if(node -> left)
    {
        child += node->left->data;
    }
    if(node -> right)
    {
        child += node->right->data;
    }

    if(child >= node->data) {
        node->data = child;
    }
    else {
        if(node->left)
        {
            node->left->data = node->data;
        }
        if(node->right)
        {
            node->right->data = node->data;
        }
    }

    childrenSum(node->left, res);
    childrenSum(node->right, res);

    int tot = 0;
    if(node->left) 
        tot  += node->left->data;
    if(node->right) 
        tot  += node->right->data;
    
    if(node->left || node->right)
    {
        node->data = tot;
    }
    res = node;
}

void inorder ( Node* root)
{
    if(!root) return;
        cout<<root->data<<" ";
        inorder(root->left);
        inorder(root->right);
}
};

int main(){
      Node* root = new Node(2);
    root->left = new Node(35);
    root->right = new Node(10);
    //root->right->left = new Node(2);
    root->left->left= new Node(2);
    root->left->right= new Node(3);
    root->right->left= new Node(5);
    root->right->right= new Node(2);
    cout<<"children sum property in binary tree:"<<"\n";
    Solution obj;
    Node* res;
    Node* ans = obj.childrenSum(root, res);
    obj.inorder(ans);
    return 0;
}
/*
children sum property in binary tree:
90 70 35 35 20 10 10
*/