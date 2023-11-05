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
public:
BSTIterator(Node * root)
{
    pushAll(root);
}
bool hasNext(){
    return !myStack.empty();
}
int next () {
    Node *tempNode = myStack.top();
    myStack.pop();
    pushAll(tempNode->right);
    return tempNode->data;
}
private :
void pushAll(Node * node){
    for(;node!= NULL;myStack.push(node), node = node->left);
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
    cout<<"BST Iterator:"<<"\n";
    BSTIterator iterator(root->left);
    while(iterator.hasNext())
    {
       cout<<(iterator.next())<<" ";
    }

   return 0;
}
/*
BST Iterator:
1 3 4 6 7
*/