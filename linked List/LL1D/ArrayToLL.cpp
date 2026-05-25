#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data1){
        data = data1;
        next = nullptr;
    }
};

node* convertArrayToLL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover = head;

    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// array traversal function

// void printLL(node* head){
//     node* temp = head;

//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<"NULL";
// }

// linked list ka total cnt 
int LengthofLL(node* head){
    node* temp = head;
    int cnt = 0;

    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int SearchAnEle(node* head,int val){
    node* temp = head;
    
    while(temp){
        if(temp->data==val) return 1;
            temp = temp->next;
    }
        return 0;
}

int main(){
    vector<int> arr = {2,4,6,8};

    node* head = convertArrayToLL(arr);

    // cout<<head->data;  head data ko return kr rha means 2

    // cout<<LL(head);


    // array traversal 
    // node* temp = head;

    // while(temp!=NULL){
    //     cout<<temp->data<<"->";
    //     temp = temp->next;
    // }
    // cout<<"NULL";

    // cout<<LengthofLL(head);

    cout<<SearchAnEle(head,2);
}