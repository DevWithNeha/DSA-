// brute force


// #include<bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//     int val;
//     node* next;

//     node(int data){
//         val = data;
//         next = NULL;
//     }
// };

// node* mergeklist(vector<node*>& lists){
//     vector<int> arr;

//     // traverse all ll aur arr me sare ele ko push kr do

//     for(int i=0;i<lists.size();i++){
//         node* temp = lists[i];

//         while(temp!=NULL){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//     }

//     // sort all value

//     sort(arr.begin(),arr.end());

//     // ll me kro
//     node* dummy = new node(-1);
//     node* tail = dummy;

//     for(int i=0;i<arr.size();i++){
//         tail->next = new node(arr[i]);
//         tail = tail->next;
//     }
//     return dummy->next;
// }

// void printlist(node* head){

//     while(head!=NULL){
//         cout<<head->val<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }

// int main(){
//     node* head1 = new node(1);
//     head1->next = new node(4);
//     head1->next->next = new node(5);

//     node* head2 = new node(1);
//     head2->next = new node(3);
//     head2->next->next = new node(5);

//     node* head3 = new node(2);
//     head3->next = new node(6);

//     vector<node*> list;

//     list.push_back(head1);
//     list.push_back(head2);
//     list.push_back(head3);

//     node* ans = mergeklist(list);

//     printlist(ans);

// }

// using heap optimal sol



#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int data){
        val = data;
        next = NULL;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->val > b->val;
    }
};


node* mergeklists(vector<node*>& list){
    priority_queue<node*,vector<node*>,compare> pq;

    // all head push into heap
    for(int i=0;i<list.size();i++){
        if(list[i]!=NULL){
            pq.push(list[i]);
        }
    }

    node* dummy = new node(-1);
    node* tail = dummy;

    while(!pq.empty()){

        // smallest node
        node* temp = pq.top();
        pq.pop();

        // add into answer list
        tail->next =  temp;
        tail = tail->next;

        if(temp->next!=NULL){
            pq.push(temp->next);
        }
    }
    return dummy->next;
}

  // print ll

    void printlist(node* head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }

int main(){
    node* head1 = new node(1);
    head1->next = new node(4);
    head1->next->next = new node(5);

    node* head2 = new node(1);
    head2->next = new node(3);
    head2->next->next = new node(5);

    node* head3 = new node(2);
    head3->next = new node(6);

    vector<node*> list;

    list.push_back(head1);
    list.push_back(head2);
    list.push_back(head3);

    node* ans = mergeklists(list);

    printlist(ans);

}



