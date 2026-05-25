#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int size;
    int *st;

public:
    Stack(int n){
        size = n;
        st = new int[size];
        top = -1;
    }

    void push(int n){
        if(top == size-1){
            cout<<"stack overflow\n";
            return;
        }
        top++;
        st[top] = n;
    }

    int pop(){
        if(top == -1){
            cout<<"stack underflow: ";
            return 0;
        }
        top--;
    }

    int peek(){
        if(top == -1){
            cout<<"stack is empty\n";
            return -1;
        }
        return st[top];
    }

    int getsize(){
        return top + 1;
    }

    bool isempty(){
        return top == -1;
    }
    void display(){
        if(top == -1){
            cout<<"stack empty\n";
            return;
        }
        for(int i=0;i<=top;i++){
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Stack s(5);

    s.push(1);
    s.push(1);
    s.push(1);


    // s.display();
    s.pop();

    // cout<<"top element: "<<s.peek()<<endl;

    // cout<<"size: "<<s.getsize()<<endl;

    // cout<<"empty: "<<s.isempty()<<endl;
  
    s.display();

    
}