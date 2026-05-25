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

int countnodes(node* root){
    if(root == NULL)
    return 0;

    return 1 + countnodes(root->left) 
    + countnodes(root->right);
}

bool CBT(node* root,int index,int totalnodes){
    if(root == NULL) 
    return true;

    if(index >= totalnodes){
        return false;
    }

    return CBT(root->left,2*index+1,totalnodes) 
    && CBT(root->right,2*index+2,totalnodes);
}

// parent >= children

bool maxheap(node* root){
    // root null
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    // left child exxit

    if(root->left){
        if(root->data < root->left->data)
        return false;

        if(maxheap(root->left) == false)
        return false;
    }
    
    if(root->right){
        if(root->data < root->right->data)
        return false;

        if(maxheap(root->right) == false)
        return false;
    }
    return true;
}

bool isheap(node* root){

    //count node in the tree

    int totalnodes = countnodes(root);

    // CBT hai ya ni

    if(CBT(root,0,totalnodes) == false)
    return false;

    // every parent >= child

    return maxheap(root);

    
}

int main(){
    
    node* root = new node(10);

    root->left = new node(9);
    root->right = new node(6);

    root->left->left = new node(7);
    root->left->right = new node(6);

    if(isheap(root)){
        cout<<"yes,it is a heap";
    } else{
        cout<<"no,it is not a heap";
    }


}