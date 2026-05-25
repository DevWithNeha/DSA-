#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
  if(n<=1) return;
  
  insertion_sort(arr,n-1);
  
  int curr = arr[n-1];
  int prev = n-2;

    while(prev >= 0 && arr[prev] > curr){
        arr[prev+1] = arr[prev];
        prev--;
    }
  arr[prev+1] = curr;
}
int main(){
    int n;
    cout<<"enter number :";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    insertion_sort(arr,n);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

}