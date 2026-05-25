#include<bits/stdc++.h>
using namespace std;
vector<int> nse(vector<int> &arr,int n){
    stack<int> st;
    vector<int> next(n);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()) next[i] = n;
        else next[i] = st.top();

        st.push(i);
    }
    return next;
}

vector<int> pse(vector<int> &arr,int n){
    stack<int> st;
    vector<int> prev(n);

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        if(st.empty()) prev[i] = -1;
        else prev[i] = st.top();

        st.push(i);
    }
    return prev;
}

int largestRectangleArea(vector<int> &heights){
    int n = heights.size();
    vector<int> next = nse(heights,n);
    vector<int> prev = pse(heights,n);

    int area = 0;

    for(int i=0;i<n;i++){
        int height = heights[i];
        int width = next[i] - prev[i] - 1;

        int maxArea = height*width;
        area = max(area,maxArea);
    }
    return area;
}

int maximumRectangle(vector<vector<int>> &matrix){
    int n = matrix.size();
    if(n==0) return 0;
    int maxArea = 0;

    int m = matrix[0].size();
    vector<int> heights(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 1){
                heights[j] += 1;
            } else{
                heights[j] = 0;
            }
        }
        maxArea = max(maxArea,largestRectangleArea(heights));
    }
    return maxArea;
}

int main(){
    vector<vector<int>> arr = {
        {1,0,1,0},
        {1,1,1,1},
        {1,1,1,0}
    };

    cout<<maximumRectangle(arr);
}