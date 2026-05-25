#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node* convertArraytoLL(vector<int> &arr){
    if(arr.size()==0) return NULL;

    node* head = new node(arr[0]);
    node* mover = head;

    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(node* head){
    node* temp = head;

    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
}

// brute force solution

node* removenthnode(node* head , int n){
    int size = 0;
    node* temp = head;

    while(temp!=NULL){
        size++;
        temp = temp->next;
    }

    // agar head delete karna ho toh
    if(size==n){
        node* temp = head;
        temp->next = head;
        delete temp;
        return head;
    }

    int target = size-n;
    temp = head;

    for(int i=1;i<target;i++){
        temp = temp->next;
    }

    node* delnode = temp->next;
    temp->next = temp->next->next;
    delete delnode;

    return head;

}

// optimal solution

/*
node* removenthnode(node* head , int n){
    node* fast = head;

    for(int i=0;i<n;i++){
        fast = fast->next;
    }

    node* slow = head;

    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;

    }

    node* delnode = slow->next;
    slow->next = slow->next->next;

    delete delnode;

    return head;
}

*/

int main(){
    vector<int> arr = {1,2,3,3,4,5};
    int n = 2;

    node* head = convertArraytoLL(arr);

    head = removenthnode(head,n);

    printLL(head);
}