// to find nth row;

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> getNthRow(int n){
//     vector<int> row;
//     long long ans = 1;

//     row.push_back(1); // first element always shoul be 1

//     for(int col=1;col<n;col++){
//         ans = ans*(n-col);
//         ans = ans/(col);
//         row.push_back(ans);
//     }
//     return row;
// }

// int main(){
//     int n;
//     cout<<"enter number: ";
//     cin>>n;

//     vector<int> result = getNthRow(n);

//     for(int x:result){
//         cout<<x<<" ";
//     }
// }


// for whole pascal triangle


// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> pascal(int n){
//     vector<vector<int>> ans;

//     for(int row=1;row<=n;row++){
//         vector<int> ansrow;
//         long long val = 1;

//         ansrow.push_back(1);

//         for(int col = 1;col<row;col++){
//             val = val*(row-col);
//             val = val/col;
//             ansrow.push_back(val);
//         }
//         ans.push_back(ansrow);
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cout<<"enter number: ";
//     cin>>n;

//     vector<vector<int>> result = pascal(n);

//    for(int i=0;i<result.size();i++){
//     for(int j=0;j<result[i].size();j++){
//         cout<<result[i][j]<<" ";
//     }
//     cout<<endl;
//    }
// }

// to find the element of nth row and rth column tndex

#include<bits/stdc++.h>
using namespace std;
int NthCthEle(int r,int c){
    
    // r = r-1;
    // c = c-1;

    long long res = 1;

    for(int i=0;i<c;i++){
        res = res*(r-i);
        res = res/(i+1);
    }
    return res;
}

int main(){
    int r;
    cout<<"enter row: ";
    cin>>r;

    int c;
    cout<<"enter column: ";
    cin>>c;

    cout<<NthCthEle(r,c);

    

}