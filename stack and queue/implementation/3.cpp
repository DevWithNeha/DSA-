#include<bits/stdc++.h>
using namespace std;
/*
int celebrity(vector<vector<int>>& M , int n){

    for(int i=0;i<n;i++){
        bool knowSomeone = false;
        bool knowByEveryone = true;

        // row wise (i kisi ko janta h)
        for(int j=0;j<n;j++){
            if( i != j && M[i][j] == 1){
                knowSomeone = true;
                break;
            }
        }

        // column wise (sab i ko jante h)
        for(int j=0;j<n;j++){
            if(i != j && M[j][i] == 0){
                knowByEveryone = false;
                break;
            }
        }
        if(!knowSomeone && knowByEveryone){
            return i;
        }
    }
    return -1;
}

*/

/*
int celebrity(vector<vector<int>>& M , int n){
    int candidate = 0;

    for(int i=1;i<n;i++){
        if(M[candidate][i] == 1){
            candidate = i;
        }
    }
    for(int i=0;i<n;i++){
        if(i == candidate) continue;

        if(M[candidate][i] == 1 || M[i][candidate] == 0){
            return -1;
        }
    }
    return candidate;
}

*/
// two pointer rule

int celebrity(vector<vector<int>>& M , int n){
    int top=0;
    int down=n-1;

    while(top<down){
        if(M[top][down]==1){
            top++; // mtlb top down ko janta h
        } 
        else if(M[down][top] == 1){
            down--;
        } else{
            top++;
            down--;
        }
    }

    int candidate = top;

    for(int i=0;i<n;i++){

        if(i == candidate) continue;
        
        if(M[candidate][i]==1 || M[i][candidate]==0){
            return -1;
        }
    }
    return candidate;
}
int main(){
    int n;
    cout<<"enter number of people: ";
    cin>>n;

    vector<vector<int>> M(n,vector<int>(n));

    cout<<"enter matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>M[i][j];
        }
        cout<<endl;
    }
        int ans = celebrity(M,n);

        if(ans == -1){
            cout<<"no celebrity found:\n ";
        } else{
            cout<<ans<<endl;
        }
    }
