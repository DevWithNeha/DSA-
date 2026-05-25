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

// node* findStartPoint(node* head){
//     unordered_map<node* ,int> mp; // yha address ke sath sath value bhi

//     node* temp = head;

//     while(temp!=NULL){
//         if(mp[temp]==1){
//             return temp;
//         }
//         mp[temp] = 1;
//         temp = temp->next;
//     }
//     return NULL;
// }

// brute force 
// using set

/*
node* findStartPoint(node* head){
    unordered_set<node*> st; // only address store kr rhe yha pe

    node* temp = head;

    while(temp!=NULL){
        if(st.find(temp)!=st.end()){
            return temp;
        }

        st.insert(temp);
        temp=temp->next;
    }
    return NULL;
}

*/

// optimal code

node* findStartPoint(node* head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            slow = head;

            while(fast!=slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        }
    }
    return NULL;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

   

    node* head = convertArraytoLL(arr);

    head->next->next->next->next = head->next->next;

    node* start = findStartPoint(head);

    if(start!=NULL){
        cout<<" cycle start at: "<<start->data;
    }else{
        cout<<"no cycle found: ";
    }


 
    // printLL(head);

}