#include<bits/stdc++.h>
using namespace std;

int partion(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int> &arr,int low,int high){
    if(low<high){
    int pidx = partion(arr,low,high);
    quickSort(arr,low,pidx-1);
    quickSort(arr,pidx+1,high);
    }
}
int main(){
    int n;
    cout<<"enter number of element :";
    cin>>n;
     vector<int> arr(n);
     cout<<"enter elements:\n";
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

    cout << "Before sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "After sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
    }
