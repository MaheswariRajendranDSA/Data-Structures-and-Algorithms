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

bool RoottoNode(Node* node, vector<int> &printNode, int x){
    if(node == NULL)
        return false;
    
    printNode.push_back(node->data);

    if(node->data == x)
    return true;

    if(RoottoNode(node->left, printNode, x) || RoottoNode(node->right, printNode, x))
    return true;

    printNode.pop_back();
    return false;
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
    cout<<"Root to node path of binary tree:"<<"\n";
    int x;
    cin>>x;
    Solution obj;
    vector<int> printNode;
    if(root == NULL) 
        cout<<"NULL";
    else
    {
    if(obj.RoottoNode(root, printNode, x))
    {
    for(int i=0;i<printNode.size();i++)
        cout<<printNode[i];
    }
    else
        cout<<"Invalid";
    }
    return 0;
    }
/*
Root to node path of binary tree:
7
137
*/