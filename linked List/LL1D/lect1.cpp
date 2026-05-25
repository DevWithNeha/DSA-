#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:
    node(int data1,node* next1){  // ye constructor ik node bna rha
        data = data1; // value store hoti hai
        next = next1; // address hoti h
    }

    public:
    node(int data1){ // isme sirf data de rhe h next automatically null ho jayega
        data = data1;
        next = nullptr;
    }
        
};

int main(){
    vector<int> arr = {2,3,8,7};
    node* y = new node(arr[0]);
    cout<<y->data;
}