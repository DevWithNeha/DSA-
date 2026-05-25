#include<bits/stdc++.h>
using namespace std;
class node{
    public:

    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// using recursion

/*
void postorder(node* root){
    if(root == NULL)
    return;

    postorder(root->left);

    postorder(root->right);

    cout<<root->data<<" ";

}

*/

void postorder(node* root){
    stack<node*> st1,st2;

    if(root == NULL)
    return;

    st1.push(root);
    
    while(!st1.empty()){
    node* temp = st1.top();
    st1.pop();

    st2.push(temp);

    if(temp->left)
    st1.push(temp->left);

    if(temp->right)
    st1.push(temp->right);
    }

    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }

}

int main(){
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->left->left->left = new node(8);

    root->right->left = new node(6);
    root->right->right = new node(7);

    postorder(root);
}



