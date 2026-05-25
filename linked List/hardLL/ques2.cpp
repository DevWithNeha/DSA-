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

node* rotate(node* head,int k){
   
    if(head == NULL || head->next == NULL || k==0) return head;
    node* temp = head;

    int len = 1;

    while(temp->next!=NULL){
        temp = temp->next;
        len++;
    }

        temp->next = head;

        k = k%len;

        int steps = len-k;

        node* newtail = head;

        for(int i = 1;i<steps;i++){
            newtail = newtail->next;
        }

        node* newhead = newtail->next;
        newtail->next = NULL;
    
    return newhead;
}


int main(){
    vector<int> arr = {4,6,3,2,5,42,2,0};
    int k = 3;

    node* head = convertArraytoLL(arr);


    head = rotate(head,k);
    
    
    printLL(head);

}