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

node* addTwo(node* l1,node*l2){
    node* dummy = new node(0);
    node* temp = dummy;

    int carry = 0;

    while(l1!=NULL || l2!=NULL || carry){
        int val1 = 0;
        int val2 = 0;

        if(l1!=NULL){
            val1 = l1->data;
            l1 = l1->next;
        }

        if(l2!=NULL){
            val2 = l2->data;
            l2 = l2->next;
        }

        int total = val1+val2+carry;

        int digit = total%10;

        int newcarry = total/10;

        node* newnode = new node(digit);
        temp->next = newnode;
        temp = temp->next;

        carry = newcarry;
    }
    return dummy->next;
}


int main(){
    node* l1 = new node(9);
    l1->next = new node(9);
    l1->next->next = new node(3);

    node* l2 = new node(5);
    l2->next = new node(6);
    l2->next->next = new node(4);

    node* ans = addTwo(l1,l2);

    printLL(ans);

    
}