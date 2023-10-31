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
int floorBST(Node *root, int val){
    int floor = -1;
    while(root){
        if(root->data ==  val){
            floor= root->data;
            return floor;
        }
        else if (val < root -> data)
        {
            root = root->left;
        }
        else {
            floor  = root->data;
            root= root->right;
        }
    }
    return floor;
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
    cout<<"Floor in binary search tree:"<<"\n";
    Solution obj;
    int val;
    cin>>val;
    int target = obj.floorBST(root, val);
    cout<<target;
    return 0;
}
/*
Floor in binary search tree:
9
8
*/