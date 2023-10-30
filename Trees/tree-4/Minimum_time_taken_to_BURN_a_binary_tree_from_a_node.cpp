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

Node* markParents(map<Node*, Node*> &parentTrack, Node* root, int start)
{
    queue<Node*> queue;
    queue.push(root);
    Node* res;
    while(!queue.empty()){
        Node* current =  queue.front();
        if(root->data == start)
        res = root;
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
    return res;
}

int minTimeToBurn(map<Node*, Node*> parentTrack, Node* res){
    map<Node*, int> visited;
    queue<Node*>queue;
    queue.push(res);
    visited[res]=1;
    int maxi = 0;

    while(!queue.empty()){
        int size = queue.size();
        int flag = 0;
        for(int i = 0; i<size;i++){
            Node* cur_node = queue.front();
            queue.pop();
            if(cur_node -> left && !visited[cur_node->left])
            {
                flag = 1;
                visited[cur_node->left] = 1;
                queue.push(cur_node->left);
            }
            if(cur_node -> right && !visited[cur_node->right])
            {
                 flag = 1;
                visited[cur_node->right] = 1;
                queue.push(cur_node->right);
            }
            if(parentTrack[cur_node] && !visited[parentTrack[cur_node]])
            {
                flag = 1;
                visited[parentTrack[cur_node]] = 1;
                queue.push(parentTrack[cur_node]);
            }
        }
        if(flag) maxi++;
    }
    return maxi;
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
    cout<<"Minimum time taken to BURN a binary tree:"<<"\n";
    Solution obj;
    int start;
    cin>>start;
    map<Node*, Node*> parentTrack;
    Node* target = obj.markParents(parentTrack, root, start);
    int res = obj.minTimeToBurn(parentTrack, target);
    cout<<res;
    return 0;
}
/*
Minimum time taken to BURN a binary tree:
start node = 5
time = 3
*/