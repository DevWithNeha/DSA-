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

// brute force 
//  tc :- o(n)+o(n)
/*
node* segregate(node* head){
    int zero = 0;
    int one = 1;
    int two = 2;

    node* temp = head;

    while(temp!=NULL){
        if(temp->data==0) zero++;
        else if(temp->data==1) one++;
        else two++;

        temp = temp->next;
    }
    temp = head;

    while(temp!=NULL){
        if(zero>0){
            temp->data = 0;
            zero--;
        }
        else if(one>0){
            temp->data = 1;
            one--;
        }
        else{
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }
    return head;
}

*/

node* segregate(node* head){
    node* zerohead = new node(-1);
    node* onehead = new node(-1);
    node* twohead = new node(-1);
    
    node* zero = zerohead;
    node* one = onehead;
    node* two = twohead;

    node* temp = head;

    while(temp!=NULL){
        if(temp->data==0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data==1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    // connect link

    if(onehead->next!=NULL){
        zero->next = onehead->next;
    }else{
        zero->next = twohead->next;
    }
    one->next = twohead->next;
    
    two->next = NULL;

    return zerohead->next;
}

int main(){
    vector<int> arr = {0,1,2,0,1,2,0};
    int n = 2;

    node* head = convertArraytoLL(arr);

    head = segregate(head);

    printLL(head);
}