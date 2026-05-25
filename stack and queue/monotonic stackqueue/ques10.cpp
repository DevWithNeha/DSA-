#include<bits/stdc++.h>
using namespace std;
// int largestRecHistogram(vector<int> &heights){
//     int n = heights.size();
//     int maxArea = 0;

//     for(int i=0;i<n;i++){
//         int h = heights[i];

//         int left = i,right = i;

//         while(left >= 0 && heights[left] >= h){
//             left--;
//         }

//         while(right < n && heights[right] >= h){
//             right++;
//         }

//         int width = right-left-1;
//         int area = heights[i] * width;

//         maxArea = max(maxArea , area);
//     }
//     return maxArea;
// }


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

int largestRecHistogram(vector<int> heights){
    int n = heights.size();

    vector<int> next = nse(heights,n);
    vector<int> prev = pse(heights,n);

    int area = 0;

    for(int i = 0;i<n;i++){
        int height = heights[i];
        int width = next[i]-prev[i]-1;
        int newArea = height * width;

        area = max(newArea,area);
    }
    return area;
}
    

    /*
    int largestRecHistogram(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i=0;i<n;i++){
            int curr;

            if(i == n){
                curr = 0;
            } else{
                curr = heights[i];
            }

            while(!st.empty() && heights[st.top()] > curr){
                int h = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()){
                    width = i;
                } else{
                    width = i - st.top() - 1;
                }
                int area = h * width;
                maxArea = max(maxArea,area);
            }
            st.push(i);
        }
        return maxArea;
    }

    */

int main(){
    vector<int> heights = {2,1,5,6,2,3};

    cout<<largestRecHistogram(heights);
}