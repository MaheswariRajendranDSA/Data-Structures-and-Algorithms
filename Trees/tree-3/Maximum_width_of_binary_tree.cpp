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

int maximumWidth(Node* node){
    if(node == NULL)
        return 0;
    
    int width = 0;
    queue<pair<Node*, int>> q;
    q.push({node, 0});

    while(!q.empty())
    {
        int size = q.size();
        int mini = q.front().second;
        int first, last;

        for(int i = 0;i < size; i++)
        {
            int node_id = q.front().second - mini;
            Node* qnode = q.front().first;
            q.pop();

            if(i == 0)
                first = node_id;
            if(i == size-1)
                last = node_id;
            
            if(qnode->left)
                q.push({qnode->left, node_id*2+1});
            if(qnode->right)
                q.push({qnode->right, node_id*2+2});
        }
        width = max( width, last - first + 1);
    }
    return width;
    }
}
;
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    cout<<"Maximum width of binary tree:"<<"\n";
    Solution obj;
    int ans = obj.maximumWidth(root);
    cout<<ans;
    return 0;
    }
/*
Maximum width of binary tree:
4
*/