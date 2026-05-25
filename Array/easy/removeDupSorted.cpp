#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

     int i=0;
    for(int j=1;j<n;j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
            arr[i] = arr[j];
        }
    }

    int k = i+1;
     for(int m = 0;m<k;m++){
        cout<< arr[m]<<" ";
     }
    
    
}
