//brute force
/*

#include<bits/stdc++.h>
using namespace std;

void medianStream(vector<int>& stream){
    vector<int> ans;

    for(int i=0;i<stream.size();i++){
        ans.push_back(stream[i]);
        sort(ans.begin(),ans.end());

        int n = ans.size();

        if(n%2==1)
        cout<<ans[n/2]<<" ";

        else
        cout<<(ans[n/2] + ans[n/2-1])/2.0<<" ";
    }
}

int main(){
    vector<int> stream = {5,15,1,3};

    medianStream(stream);
}

*/

// optimal sol

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:

    priority_queue<int> leftmaxheap;

    priority_queue<int,vector<int>,greater<int>> rightminheap;



    //function to insert heap
    void insertheap(int &x){
        
        // first element

        if(leftmaxheap.empty()){
            leftmaxheap.push(x);
            return;
        }

        // insert according to value

        if(x>leftmaxheap.top()){
            rightminheap.push(x);
        }else{
            leftmaxheap.push(x);
        }
    }

    //function to balance heap
    void balanceheap(){

        // left size > right size + 1

        if(leftmaxheap.size() > rightminheap.size()+1){
            rightminheap.push(leftmaxheap.top());
            leftmaxheap.pop();
        }
        //right size > left size
        else if(rightminheap.size() > leftmaxheap.size()){
            leftmaxheap.push(rightminheap.top());
            rightminheap.pop();
        }
    }

    //funtion to return median
    double getmedian(){
        if(leftmaxheap.size() > rightminheap.size()){
            return leftmaxheap.top();
        } 

        return (leftmaxheap.top() + rightminheap.top()) / 2.0;
    }
};

int main(){
    solution obj;

    vector<int> stream = {5,15,1,3};

    for(int i=0;i<stream.size();i++){
        obj.insertheap(stream[i]);

        cout<<obj.getmedian()<<" ";
    }
}