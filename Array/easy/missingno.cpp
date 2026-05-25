#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"enter number: ";
    cin>>n;

    vector<int> arr(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    int total = n*(n+1)/2;
    int sum = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    cout<<"missing numaber are: "<<total-sum;

}

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int x1 = 0;
//     int x2 = 0;

//     vector<int> arr ={1,2,4,5};
//     int n = 5;
    

//     for(int i=0;i<=n;i++){
//         x1 = x1^i;
//     }
//     for(int i=0;i<arr.size();i++){
//         x2 = x2^arr[i];
//     }
    

//     cout<<(x1^x2);
// }
