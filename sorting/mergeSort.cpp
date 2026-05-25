#include<bits/stdc++.h>
using namespace std;

//combine karne ke liye 2 alg alg array ko
void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int i=low;//left
    int j=mid+1;//right
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
        temp.push_back(arr[i]);
        i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
     while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=low;idx<=high;idx++){ //idx=low -> high
        arr[idx]=temp[idx-low];            // arr[idx]=temp[idx-i]
    }

}
void mergeSort(vector<int> &arr,int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    //left
    mergeSort(arr,low,mid);
    //right
    mergeSort(arr,mid+1,high);
    //merge karne ke liye left aur right ko
    merge(arr,low,mid,high);
}

int main(){
    int n;
    cout<<"enter number of element: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter element\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
cout << "Before sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// void merge(vector<int> &arr,int low,int mid,int high){
//     vector<int> temp;
//     int i= low;
//     int j=mid+1;
//     while(i<=mid && j<=high){
//         if(arr[i]<=arr[j]){
//         temp.push_back(arr[i]);
//         i++;
//         }
//         else{
//             temp.push_back(arr[j]);
//             j++;
//         }
//     }
//     while(i<=mid){
//         temp.push_back(arr[i]);
//         i++;
//     }
//     while(j<=high){
//         temp.push_back(arr[j]);
//         j++;
//     }
//     for(int idx = low ; idx <= high ; idx++){
//         arr[idx] = temp[idx-low];
//     }
// }
// void mergeSort(vector<int> &arr,int low,int high){
//     if(low >= high) return;
//     int mid = (low+high)/2;
//     mergeSort(arr,low,mid);
//     mergeSort(arr,mid+1,high);
//     merge(arr ,low,mid,high);
// }
// int main(){
//     vector<int> arr = {5,4,3,2,1};

//     mergeSort(arr,0,arr.size()-1);

//     for(int x:arr) cout<<x<<" ";
//     return 0;
// }
