// #include<bits/stdc++.h>
// using namespace std;

// void printdivisiors(int n){
//     for(int i=1;i<=n;i++){
//         if(n%i==0){
//             cout<< i <<" ";
//         }
//     }
// }
// int main(){
//     int n;
//     cout<<"enter number: ";
//     cin>>n;
//     printdivisiors(n);
    
// }

#include<bits/stdc++.h>
using namespace std;

void printdivisior(int n){
    vector<int> ls;

// o(sqrt(n))
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ls.push_back(i);
            if((n/i)!=i){
                ls.push_back(n/i);
            }
        }

    }
    // o(no of factors * log(no of factors)):n is the number of factors
    sort(ls.begin(),ls.end()); // sort kr dega
    for(auto it : ls) cout<< it <<" ";
}

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    printdivisior(n);
}