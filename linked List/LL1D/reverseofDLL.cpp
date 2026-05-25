// brute force using array

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* back;


    node(int val){
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

node* convertarraytoDLL(vector<int> &arr){
    if(arr.size()==0) return NULL;

    node* head = new node(arr[0]);
    node* prev = head;

    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

void printDLL(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// brute force using array

/*
node* reverseDLL(node* head){
    if(head==NULL) return head;

    vector<int> arr;
    node* temp = head;

    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    temp = head;
    int i = arr.size()-1;

    while(temp!=NULL){
        temp->data=arr[i];
        i--;
        temp = temp->next;
    }
    return head;
}

*/

// brute force using stack

/*
node* reverseDLL(node* head){
    if(head==NULL) return head;

    stack<int> st;

    node* temp = head;

    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

*/

//optimal code

// node* reverseDLL(node* head){
//     if(head==NULL) return head;

//     node* temp = head;
//     node* prev = NULL;

//     while(temp!=NULL){
//         prev = temp->back;

//         temp->back = temp->next;
//         temp->next = prev;

//         temp = temp->back;

//         if(prev!=NULL){
//             head = prev->back;
//         }
//     }
//     return head;
// }

node* reverseDLL(node* head){
    node* temp = head;
    node* prev = NULL;

    while(temp!=NULL){
        node* front = temp->next;

        temp->next = prev;
        prev = temp;
        temp = front;

    }
    return prev;
}

int main(){
    vector<int> arr = {2,4,6,87};

    node* head = convertarraytoDLL(arr);

    cout<<"before reverse: ";
    printDLL(head);

    head = reverseDLL(head);

    cout<<"after reverse: ";
    printDLL(head);
}


