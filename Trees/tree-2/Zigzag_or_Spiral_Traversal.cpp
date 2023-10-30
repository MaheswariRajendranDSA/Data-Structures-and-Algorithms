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
vector<vector<int>> printZigzagTree(Node* node){
    vector<vector<int>> res;
    if(node == NULL){
    return res;
    }

    queue <Node*> nodeQu;
    nodeQu.push(node);
    bool leftToRight = true;

    while(!nodeQu.empty())
    {
        int size = nodeQu.size();
        vector<int> row(size);

        for(int i=0;i<size;i++)
        {
            Node* node = nodeQu.front();
            nodeQu.pop();
            int index = (leftToRight)?i:size-1-i;
            row[index] = node->data;
            if(node -> left)
            nodeQu.push(node->left);
             if(node -> right)
            nodeQu.push(node->right);
        }
            leftToRight = !leftToRight;
            for(int i=0;i<row.size();i++)
            cout<<row[i]<<" ";
            cout<<"\n";
            res.push_back(row);
    }
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
    root->left->left->left= new Node(8);
    root->left->left->right= new Node(9);
    root->left->right->left= new Node(10);
    root->left->right->right= new Node(11);
     root->left->right->right->left= new Node(12);
      root->left->right->right->right= new Node(13);
    cout<<"Zigzag Tree is:"<<"\n";
    Solution obj;
    obj.printZigzagTree(root);
    return 0;
}
/*
Zigzag Tree is:
1
3 2
4 5 6 7
11 10 9 8
12 13
*/