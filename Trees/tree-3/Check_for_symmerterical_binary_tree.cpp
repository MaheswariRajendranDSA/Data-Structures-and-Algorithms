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

bool checkSymmetrical(Node* left, Node* right){
    if(left == NULL || right == NULL)
        return left == right;
    
    if(left->data != right->data) return false;
    
    return checkSymmetrical(left->left, right->right) && checkSymmetrical(left->right, right->left);
}

};
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    //root->right->left = new Node(2);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(5);
    root->right->right= new Node(4);
    cout<<"Check symmetrical binary tree:"<<"\n";
    Solution obj;
    bool Mirror;
    if(root == NULL) 
        Mirror = 1;
    else
    {
    bool Mirror = obj.checkSymmetrical(root->left, root->right);
    if(Mirror)
        cout<<"TRUE"<<"\n";
    else
        cout<<"FALSE"<<"\n";
    }
    return 0;
}
/*
Check symmetrical binary tree:
TRUE
*/