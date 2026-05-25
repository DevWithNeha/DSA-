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

/*
node* middledelEle(node* head){

    if(head==NULL || head->next==NULL) return NULL;

    node* prev = NULL;
    node* fast = head;
    node* slow = head;

    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

*/

node* middledelEle(node* head){
    int size = 0;
    node* temp = head;

    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    temp = head; // temp reset ho gya h
    int mid = (size/2);

    for(int i=0;i<mid-1;i++){
        temp = temp->next;
    }
    node* delnode = temp->next;
    temp->next = temp->next->next;
    delete delnode;
    return head;

}

int main(){
    vector<int> arr = {1,2,3,9,4,5};
    int n = 2;

    node* head = convertArraytoLL(arr);

    head = middledelEle(head);

    printLL(head);
}