// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2,5,2,3,3};
    
    
//     int result = 0;
//     for(int x:arr) {
//         result ^= x;
//     }
//     cout<< result;
    

// }

// with the help of hashing

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     cout<<"enter number: ";
//     cin>>n;

//     vector<int> arr(n);
//     for(int i =0;i<n;i++){
//         cin>>arr[i];
//     }

//     // find maximum element 
//     int max = arr[0];
//     for(int i=1;i<n;i++){
//         if(arr[i]>max);
//         max = arr[i];
//     }

//     // create hash array
//     int hash[max+1] = {0};

//     // frequency count
//     for(int i=0;i<n;i++){
//         hash[arr[i]]++;
//     }

//     // find single element
//     for(int i=0;i<=max;i++){
//         if(hash[i]==1){
//             cout<<i<<" ";
//         }
//     }
//     return 0;

// }

//brute force
// tc = o(n^2)
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==1){
            cout<<arr[i];
            break;
        }
    }

}