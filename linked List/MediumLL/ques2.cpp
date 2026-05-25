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

//brute force 
// using stack

// node* reverseLL(node* head){
//     stack<int> st;
//     node* temp = head;

//     while(temp!=NULL){
//         st.push(temp->data);
//         temp=temp->next;
//     }

//     temp = head;
//     while(temp!=NULL){
//         temp->data = st.top();
//         st.pop();
//         temp=temp->next;
//     }
//     return head;
// }

// using array

/*
node* reverseLL(node* head){
    vector<int> arr;
    node* temp = head;

    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    temp = head;
    int i= arr.size()-1;
    while(temp!=NULL){
        temp->data = arr[i];
        i--;
        temp=temp->next;
    }
    return head;
}

*/

// node* reverseLL(node* head){
//     if(head==NULL) return NULL;

//     node* temp = head;
//     node* prev = NULL;

//     while(temp!=NULL){
//         node* front = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = front;
//     }
//     return prev;
// }

// using recursion
node* reverseLL(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newHead = reverseLL(head->next);

    node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}


int main(){
    vector<int> arr = {4,6,3,2};

    node* head = convertArraytoLL(arr);

    head = reverseLL(head);

    printLL(head);

   

}