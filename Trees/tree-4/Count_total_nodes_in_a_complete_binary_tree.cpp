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

int countTotalinCompleteBT(Node* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = findLeftHeight(root);
    int rightHeight = findRightHeight(root);

    if(leftHeight == rightHeight)
        return (1<<leftHeight)-1;
    return 1+countTotalinCompleteBT(root->left) + countTotalinCompleteBT(root->right);
}
int findLeftHeight(Node* node){
    int hght = 0;

    while(node) {
        node = node->left;
        hght++;
    }
    return hght;
}
int findRightHeight(Node* node){
    int hght = 0;

    while(node) {
        node = node->right;
        hght++;
    }
    return hght;
}
};
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->left->left= new Node(4);
    root->left->left->right= new Node(7);
    root->right->left= new Node(5);
    root->right->right= new Node(6);
    cout<<"Count total nodes in a complete binary tree:"<<"\n";
    Solution obj;
    int res= obj.countTotalinCompleteBT(root);
    cout<<res;
    return 0;
}
/*
Count total nodes in a complete binary tree:
7
*/