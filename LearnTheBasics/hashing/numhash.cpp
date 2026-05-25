#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter " <<n<< "numbers: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompute
    int hash[15] ={0};
    for(int i=0;i<n;i++){
        hash[arr[i]] +=1;
    }

    int q;
    cout<<"enter number of queries: ";
    cin>>q;
    while(q--){
        int number;
        cout<<"enter number to find frequency: ";
        cin>>number;
        //fetch
        cout<<"frequency = " <<hash[number]<<endl;   
     }
}
