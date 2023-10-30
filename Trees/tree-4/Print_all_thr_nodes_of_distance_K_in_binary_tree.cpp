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

void markParents(Node* root, unordered_map<Node*, Node*> &parentTrack, Node* target)
{
    queue<Node*> queue;
    queue.push(root);

    while(!queue.empty()){
        Node* current =  queue.front();
        queue.pop();
        if(current->left){
            parentTrack[current->left] = current;
            queue.push(current->left);
        }
        if(current->right){
            parentTrack[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<int> printDistanceKNodes(Node* node, Node* res, int distance){
    unordered_map<Node*, Node*> parentTrack;
    markParents(node, parentTrack, res);
    unordered_map<Node*, int> visited;
    queue<Node*>queue;
    queue.push(res);
    visited[res]=1;
    int cur_level = 0;

    while(!queue.empty()){
        int size = queue.size();
        if(cur_level == distance)
            break;
        cur_level++;

        for(int i = 0; i<size;i++){
            Node* cur_node = queue.front();
            queue.pop();
            if(cur_node -> left && !visited[cur_node->left])
            {
                visited[cur_node->left] = 1;
                queue.push(cur_node->left);
            }
            if(cur_node -> right && !visited[cur_node->right])
            {
                visited[cur_node->right] = 1;
                queue.push(cur_node->right);
            }
            if(parentTrack[cur_node] && !visited[parentTrack[cur_node]])
            {
                visited[parentTrack[cur_node]] = 1;
                queue.push(parentTrack[cur_node]);
            }
        }
    }
    vector<int> result;
    while(!queue.empty()){
        Node* node_val = queue.front();
        queue.pop();
        result.push_back(node_val->data);
    }
    return result;
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
    cout<<"Print all the nodes of distance K in binary tree:"<<"\n";
    int k;
    cin>>k;
    Solution obj;
    Node* target = root->left;
    vector<int> resultNodes = obj.printDistanceKNodes(root, target, k);
    for(int i = 0; i < resultNodes.size();i++)
        cout<<resultNodes[i]<<" ";
    return 0;
}
/*
Print all the nodes of distance K in binary tree:
distance = 1
nodes = 4 5 1
*/