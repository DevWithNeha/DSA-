// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int a,b;
//     cout<<"enter a and b: ";
//     cin>>a>>b;

//     while(a>0 && b>0){
//         if(a>b) a=a%b;
//         else    b=b%a;
//     }
//     if(a==0) cout<<b;
//     else cout<<a;
// }

// #include<bits/stdc++.h>
// using namespace std;
// // time complexity :- o(min(a,b)) // both for best and worst case
// int main(){
//     int a,b;
//     cout<<"enter a and b: ";
//     cin>>a>>b;
//     int gcd=0;
//     for(int i=1;i<(min (a,b));i++){
//         if(a%i==0 && b%i==0){
//             gcd = i;
//         }
//     }
//     cout<<gcd;
// }


//subtraction-method

//gcd me 2 numbers lete h dono ka lcm nikalte h dono ka 
//sbse bda common number jo dono ko completelly divide kr dee whi gcd hota h
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a==0) return b;
    if(b==0) return a;
    while(a != b){
        if(a > b) a = a-b;
        else b=b-a;
    }
    return a;
}
int main(){
    int a,b;
    cout<<"enter a and b: ";
    cin>>a>>b;
    cout<< gcd(a,b);
}
