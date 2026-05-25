 #include<bits/stdc++.h>
 using namespace std;

 int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    int dup = n;
    int sum=0;
    while(n>0){
       
       int ld = n%10;
       n=n/10;
       sum=sum+(ld*ld*ld);

    }
    if(dup==sum) cout<<"true";
    else cout<< "false";
 }