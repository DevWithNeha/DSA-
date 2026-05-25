#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"enter number: ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int num;
    cout<<"enter num: ";
    cin>>num;

    bool found = false;

    for(int i=0;i<n;i++){
        if(arr[i] == num){
        cout<<"element found at index: "<<i<<endl;
        found =true;
        }
    }
    if(!found){
        cout<<"element not found";
    }
    
}