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

// brute force using hashmap

/*
node* intersectionY(node* headA,node* headB){
    unordered_map<node* , int> mp;

    node* temp = headA;

    while(temp!=NULL){
        mp[temp] = 1;
        temp = temp->next;
     }

     temp = headB;
     while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            return temp;
        }
        temp = temp->next;
     }
     return NULL;
}

*/

// brute force tc = o(n*m)

/*
node* intersectionY(node* headA,node* headB){
    node* a = headA;

    while(a!=NULL){
        node* b = headB;
        while(b!=NULL){
            if(a==b) return a;
            b = b->next;
        }
        a = a->next;
    }
    return NULL;
}

*/

// optimal

node* intersectionY(node* headA,node* headB){
    node* a = headA;
    node* b = headB;

    while(a!=b){
        if(a==NULL){
            a = headB;
        } else{
            a = a->next;
        }

        if(b==NULL){
            b = headA;
        } else{
            b = b->next;
        }
    }
    return a;
}

int main(){
    node* common = new node(7);
    common->next = new node(8);

    node* headA = new node(3);
    headA->next = new node(1);
    headA->next->next = common;

    node* headB = new node(1);
    headB->next = new node(2);
    headB->next->next = new node(4);
    headB->next->next->next = new node(5);
    headB->next->next->next->next = common;

    node* ans = intersectionY(headA,headB);

    if(ans){
        cout<<"yes intersection"<<" = "<<ans->data;
    }else{
        cout<<"no intersection ";
    }

}