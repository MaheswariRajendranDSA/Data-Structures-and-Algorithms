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

vector<vector<int>> verticalTraversal(Node* node){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> todo;
    todo.push({node, {0,0}});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* tempnode = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(tempnode->data);

        if(tempnode->left)
        todo.push({tempnode->left, {x-1, y+1}});

        if(tempnode->right)
        todo.push({tempnode->right, {x+1, y+1}});
    }
    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> temp;
        for(auto q : p.second){
            temp.insert(temp.end(), q.second.begin(), q.second.end());
        }
        for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<" ";
        cout<<"\n";
        ans.push_back(temp);
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
    cout<<"Vertical order traversal of binary tree:"<<"\n";
    Solution obj;
    obj.verticalTraversal(root);
    return 0;
}
/*
Vertical order traversal of binary tree:
8
4
2 9 10
1 5 6 12
3 11
7 13
*/