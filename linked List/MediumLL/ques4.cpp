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

// brute force solution
// using hashset

/*
bool detectLoopLL(node* head){
    unordered_set<node*> st;

    node* temp = head;

    while(temp!=NULL){
        // means element already present h
        if(st.find(temp)!=st.end()){
            return true;
        }

        st.insert(temp);
        temp = temp->next;
    }
    return false;
}

*/

// optimal solution

bool detectLoopLL(node* head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL &&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

   

    node* head = convertArraytoLL(arr);

    // loop present karne ke liye
     head->next->next->next->next = head->next->next;

    bool hasloop = detectLoopLL(head);

    if(hasloop){
        cout<<"loop present";
    }else{
        cout<<"not present";
    }

    // printLL(head);

}