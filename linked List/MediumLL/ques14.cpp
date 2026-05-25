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


// one method tc = o(n) sc = o(1)

/*
node* reverse(node* head){
    node* temp = head;
    node* prev = NULL;

    while(temp!=NULL){
        node* nextnode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
    return prev;
}

node* addOne(node* head){
    head = reverse(head);

    node* temp = head;
    int carry = 1;

    while(temp!=NULL){
        int sum = temp->data+carry;
        temp->data = sum%10;
        carry = sum/10;

        if(carry == 0) break;

        if(temp->next == NULL){
            temp->next = new node(carry);
            break;
        }
        temp = temp->next;
    }
    return reverse(head);
}

*/

int helper(node* head){
    if(head == NULL) {
        return 1;
    }

    int carry = helper(head->next);

    int sum = head->data + carry;

    head->data = sum% 10;

    return sum/10;

}

node* addOne(node* head){
    int carry = helper(head);

    if(carry!=0){
        node* newhead = new node(carry);
        newhead->next = head;
        return newhead;
    }

    return head;
}
int main(){
    vector<int> arr = {9,9,9};

    node* head = convertArraytoLL(arr);

    head = addOne(head);

    printLL(head);
}