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
void preorder(node* root){
    if(root == NULL)
    return;

    cout<<root->data<<" ";

    preorder(root->left);

    preorder(root->right);
}

*/

// using stack


void preorder(node* root){

    if(root == NULL)
    return;

    stack<node*> st;

    st.push(root);

    while(!st.empty()){

        node* temp = st.top();
        st.pop();

        cout<< temp->data<<" ";

        if(temp->right){
            st.push(temp->right);
        }

        if(temp->left){
            st.push(temp->left);
        }
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

    preorder(root);
}