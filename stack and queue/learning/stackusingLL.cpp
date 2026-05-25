#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int x){
            data = x;
            next = NULL;
        }
};

class Stack{
    node* top;

    public:
        Stack(){
            top = NULL;
        }

        // push operation

void push(int x){
    node* newnode = new node(x);
    newnode->next = top;
    top = newnode;
}

// pop operation

int pop(){
    if(top == NULL){
        cout<<"stack empty\n";
        return -1;
    }

    int val = top->data;
    node* temp = top;
    top = top->next;
    delete temp;

    return val;
}

int peek(){
    if(top==NULL) return -1;
    return top->data;
}

bool isempty(){
    return top == NULL;
}

void display(){
    node* temp = top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.display();

    cout<<"top: "<<s.peek()<<endl;
    cout<<"empty? "<<s.isempty()<<endl;

    s.pop();
    s.display();
}