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

bool isLeaf (Node* node)
{
    return !(node->left && node->right);
}

void addLeftBoundary(Node* node, vector<int> &res){
    Node* cur = node -> left;
     while(cur){
        if(!isLeaf(cur))
            res.push_back(cur->data);
        if(cur -> left)
            cur = cur->left;
        else
            cur = cur->right; 
     }
}

void addRightBoundary(Node* node, vector<int> &res){
    Node* cur = node -> right;
     while(cur){
        if(!isLeaf(cur))
            res.push_back(cur->data);
        if(cur -> right)
            cur = cur->right;
        else
            cur = cur->left; 
     }
}

void addLeaves(Node* node, vector<int> &res){
    if(isLeaf(node)){
        res.push_back(node->data);
        return;
    }

    if(node ->left) addLeaves(node -> left, res);
    if(node ->right) addLeaves(node -> right, res);
}
vector<int> printBoundaryTraversal(Node* node){
    vector<int> res;
    if(!node) return res;
    if(!isLeaf(node)){
        res.push_back(node->data);
    }

    addLeftBoundary(node, res);
    addLeaves(node, res);
    addRightBoundary(node, res);
    return res;
}



int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->left->left->left= new Node(8);
    root->left->left->right= new Node(9);
    root->left->right->left= new Node(10);
    root->left->right->right= new Node(11);
    root->left->right->right->left= new Node(12);
    root->left->right->right->right= new Node(13);
    vector<int>res;
    cout<<"Boundary Traversal of binary tree:"<<"\n";

    vector<int> ans = printBoundaryTraversal(root);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}
/*
Boundary Traversal of binary tree:
1 2 4 8 9 10 12 13 6 7 3
*/