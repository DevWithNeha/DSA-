// brute force
// array me daalo
// sort kro
// k-1 ko return kr do

/*

#include<bits/stdc++.h>
using namespace std;
int kthsmallestmatrix(vector<vector<int>>& mat,int k){
    int n = mat.size();

    vector<int> temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(mat[i][j]);
        }
    }
    sort(temp.begin(),temp.end());

    return temp[k-1];
}

int main(){
    vector<vector<int>> mat = {
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };
    int k = 8;

    cout<<kthsmallestmatrix(mat,k);
}

*/

// using min heap

/*

#include<bits/stdc++.h>
using namespace std;

int kthsmallest(vector<vector<int>>& matrix,int k){

    int n = matrix.size();

    //min heap create kro
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;

    //first colum insert kro

    for(int i=0;i<n;i++){
        pq.push({matrix[i][0],{i,0}});
    }
    
    // remove k-1 ele

    while(k>1){
        pair<int,pair<int,int>> curr = pq.top();
        pq.pop();

        int val = curr.first;

        int row = curr.second.first;
        
        int col = curr.second.second;

        if(col+1<n){
            pq.push({matrix[row][col+1] , {row,col+1}});
        }
        k--;
    }
    return pq.top().first;
}

int main(){
    vector<vector<int>> matrix = {
        {1,5,9},
        {10,11,12},
        {12,13,15}
    };

    int k = 8;

    cout<< kthsmallest(matrix,k);
}

*/

// using binary search optimal sol

#include<bits/stdc++.h>
using namespace std;

int countlessEqual(vector<vector<int>>& matrix,int mid){
    int n = matrix.size();

    int count = 0;

    int row = n-1;
    int col = 0;

    // staircase traversal
    while(row >= 0 && col < n){
        if(matrix[row][col] <= mid){

            // upper ke sab ele bhi <= mid honge
            count += row+1;
            col++;
        } else{
            row--;
        }
    }
    return count;
}

int kthsmallestEleMat(vector<vector<int>>& matrix,int k){
    int n = matrix.size();
    int low  = matrix[0][0];
    int high = matrix[n-1][n-1];

    while(low<=high){
        int mid = (low+high)/2;

        int count = countlessEqual(matrix,mid);

        if(count<k){
            low = mid+1;
        } else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> mat = {
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };

    int k = 8;

    cout<<kthsmallestEleMat(mat , k);
}
