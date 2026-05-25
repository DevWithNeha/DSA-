#include<bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> ans;

    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;

    while(left<=right && top<=bottom){

        // print first top row(left->right) 
        for(int i = left;i<=right;i++){
            ans.push_back(matrix[top][i]);
            
        }
        top++;
    

    // print last right column(top->bottom)
    for(int i=top;i<=bottom;i++){
        ans.push_back(matrix[i][right]);
        
    }
    right--;

    // bottom row(right to left)
    if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }
            bottom--;
    }

    // left column(bottom to top)
    if(left<=right){
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
           
        }
             left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> result = spiral(matrix);

    for(int x:result){
        cout<<x<<" ";
    }
    
}

