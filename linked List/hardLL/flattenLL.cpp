
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* child;

    Node(int val){
        data = val;
        next = NULL;
        child = NULL;
    }
};

Node* merge(Node* a,Node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;

    Node* result;

    if(a->data < b->data){
        result = a;
        result->child = merge(a->child,b);
    } else{
        result = b;
        result->child = merge(a,b->child);
    }
    result->next = NULL;
    return result;

}

Node* flatten(Node* head){
    if(head == NULL || head->next == NULL) return head;

    head->next = flatten(head->next);

    head = merge(head,head->next);


}

void printList(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}



int main(){

    /*
        5 -> 10 -> 19
        |     |     |
        7     20    22
        |           |
        8           50
        |
        30
    */

    Node* head = new Node(5);
    Node* n10 = new Node(10);
    Node* n19 = new Node(19);

    head->next = n10;
    n10->next = n19;

    // 5 list
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    // 10 list
    n10->child = new Node(20);

    // 19 list
    n19->child = new Node(22);
    n19->child->child = new Node(50);

    head = flatten(head);

    printList(head);

    return 0;
}