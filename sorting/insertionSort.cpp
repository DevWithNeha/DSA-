
// by swaping
// #include<bits/stdc++.h>
// using namespace std;

// void insertion_sort(int arr[],int n){
//     for(int i=0;i<=n-1;i++){
//         int j = i; // index i = current element(jo insert karna h) 
//         //index j = us element ko left side me move karne ke liye pointer
//         while(j>0 && arr[j-1]>arr[j]){
//             swap(arr[j-1],arr[j]);
//             j--;
//         }
        
//     } 
// }
// int main(){
//     int n;
//     cout<<"enter number :";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//         cin>>arr[i];

//     insertion_sort(arr,n);

//     for(int i=0;i<n;i++) {
//         cout<<arr[i]<<" ";
//     }

// }

// by shifting

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){

    for(int i=1;i<n;i++){
    int curr = arr[i];
    int prev = i-1;

    while(prev>=0 && arr[prev] > curr){
        arr[prev+1] = arr[prev];
        prev--;
        }
        arr[prev+1] = curr; // placing the curr element in its correct position
    }
}
int main(){
    int n=5;
    int arr[] = {5,4,3,2,1};

    insertionSort(arr,n);
    
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    return 0;

}