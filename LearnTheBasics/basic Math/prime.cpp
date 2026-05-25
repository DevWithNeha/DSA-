//  #include<bits/stdc++.h>
//  using namespace std;
// //  time complexity :- o(n)
//  int main(){
//     int n;;
//     cout<<"enter number: ";
//     cin>>n;
//     int cnt=0;
//     for(int i=1;i<=n;i++){
//         if(n%i==0){
//             cnt++;
//         }
        
//     }
//     if(cnt==2) cout<<"yes";
//         else cout<<"no";
//  }

#include<bits/stdc++.h>
using namespace std;
// time complexity :- o(sqrt(n))
int main(){
     int n;;
    cout<<"enter number: ";
    cin>>n;
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
        }
        if((n/i)!=i) cnt++;
        
    }
    if(cnt==2) cout<<"yes";
        else cout<<"no";
 }

