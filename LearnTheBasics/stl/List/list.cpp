#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;

    list<int> n(5,100);
    for(int i:n){
        cout<<i<<" ";
    }cout<<endl;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    for(int i:l){
        cout<<i<<" ";
    }cout<<endl;

    l.erase(l.begin());
    cout<<"after erase: "<<endl;
    for(int i:l){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"size of the list: "<<l.size()<<endl;
}