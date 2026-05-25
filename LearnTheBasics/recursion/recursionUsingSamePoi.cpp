#include<bits/stdc++.h>
using namespace std;
void reverseArray(int arr[],int i,int n){
  if(i>=n/2)
  return;

   swap(arr[i],arr[n-i-1]);
   return reverseArray(arr,i+1,n);
}

int main() {

    int n;
    cout<<"enter size";
    cin>>n;

    int arr[n];
    cout<<"enter size of element: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    reverseArray(arr,0,n);

    cout<<"reveresed Array:";
     for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";


}

