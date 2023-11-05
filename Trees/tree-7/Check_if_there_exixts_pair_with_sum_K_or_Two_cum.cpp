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
class BSTIterator {
private:
    stack<Node *> myStack;
    bool reverse = true;
public:
BSTIterator(Node * root, bool isReverse)
{
    reverse = isReverse;
    pushAll(root);
}
bool hasNext(){
    return !myStack.empty();
}
int next () {
    Node *tempNode = myStack.top();
    myStack.pop();
    if(!reverse)
    pushAll(tempNode->right);
    else 
    pushAll(tempNode->left);
    return tempNode->data;
}
private :
void pushAll(Node * node){
    for(;node!= NULL;)
    {
    myStack.push(node);
    if(reverse == true)
        node = node->right;
    else
        node = node->left;
    }
}
};
class Solution {
public:
bool findTarget(Node *node, int K){
    if(!node) return false;
    BSTIterator l(node, false);
    BSTIterator r(node, true);
    int i = l.next();
    int j = r.next();
    while(i<j){
        if(i+j == K) return true;
        if(i+j<K) i = l.next();
        else
        j = r.next();
    }
    return false;
}
};
int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left= new Node(1);
    root->left->right= new Node(6);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(7);
    root->right->right= new Node(14);
    root->right->right->left= new Node(13);
    cout<<"Two Sum:"<<"\n";
    Solution obj;
    int K;
    cin>>K;
    bool target = obj.findTarget(root, K);
    if(target)
        cout<<"TRUE";
    else 
        cout<<"FALSE";
   return 0;
}
/*
Two Sum:
11
TRUE
*/