#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q;

    public:
    //push operation
    void push(int x){
        int size = q.size();
        q.push(x);

        // rotate kr rhe h 
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }

int pop(){
    int val = q.front();
    q.pop();
    return val;
}

int top(){
    return q.front();
}

bool empty(){
    return q.empty();
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"top: "<<s.top()<<endl;

    s.pop();
    cout<<"top after top: "<<s.top()<<endl;

    s.pop();
    cout<<"next: "<<s.top()<<endl;

}