#include<bits/stdc++.h>
using namespace std;

// vector<int> primefactor(int n){

//     vector<int> ans;
//     for(int i=2;i*i<=n;i++){
//         while(n%i==0){
//             ans.push_back(i);
//             n /= i;
//         }
//     }
//     if(n>1) ans.push_back(n);

//     return ans;
// }

void primefactor(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            cout<<i<<" ";
            n /= i;
        }
    }
    if(n>1) cout<<n<<" ";
}

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;

    primefactor(n);

    // vector<int> res = primefactor(n);

    // for(int x:res){
    //     cout<<x<<" ";
    // }

    
}