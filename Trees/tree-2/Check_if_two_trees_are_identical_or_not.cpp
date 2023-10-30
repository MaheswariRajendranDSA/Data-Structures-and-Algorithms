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
bool checkIdenticalTree(Node* node1, Node* node2){
    if(node1 == NULL || node2 == NULL){
    return (node1 == node2);
    }

    return ((node1->data == node2->data) && checkIdenticalTree(node1->left, node2-> left)
    && checkIdenticalTree(node1->right, node2-> right));
}
};
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->right->right= new Node(4);
    root->right->right->right= new Node(5);

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    //root->right->left = new Node(2);
    root1->right->right= new Node(4);
    //root1->right->right->right= new Node(5);
    cout<<"Check if two trees are identical or not:"<<"\n";
    Solution obj;
    bool res = obj.checkIdenticalTree(root ,root1);
    if(res == 1)
    cout<<"TRUE";
    else
    cout<<"FALSE";
    return 0;
}
/*
Check if two trees are identical or not:
TRUE
*/