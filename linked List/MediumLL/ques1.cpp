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

// node* middleEleLL(node* head){
//     node* temp = head;
//     int cnt = 0;
    
//     while(temp!=NULL){
//         cnt++;
//         temp = temp->next;
//     }

//     int middlenode = (cnt/2)+1;
//     temp = head;

//     while(temp!=NULL){
//         middlenode--;
//         if(middlenode==0) break;

//         temp = temp->next;
//     }
//     return temp;
// }

node* middleEleLL(node* head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {4,6,3,2};

    node* head = convertArraytoLL(arr);

    // printLL(head);

    node* mid = middleEleLL(head);
    cout<<mid->data;

}