#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &arr,int n,int index){
   if(index == n-1) return;

   int miniindex = index;

   for(int i = index+1;i<n;i++){
    if(arr[i]<arr[miniindex]){
        miniindex = i;
    }
   }
   swap(arr[index],arr[miniindex]);

   selection_sort(arr,n,index+1);
}
int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selection_sort(arr,n,0);

    for(int x:arr) cout<<x<<" ";
    return 0;
}