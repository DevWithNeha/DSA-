#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter element: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int smallest = arr[0];
    int Ssmallest = INT_MAX;

    int idxsmallest = 0;
    int idxSsmallest = -1;

    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            Ssmallest = smallest;
            idxSsmallest = idxsmallest;

            smallest = arr[i];
            idxsmallest = i;
        }

        else if(arr[i] != smallest && arr[i]<Ssmallest){
            Ssmallest = arr[i];
            idxSsmallest = i;
        }
    }

    cout<<Ssmallest<<" "<<idxSsmallest;
}