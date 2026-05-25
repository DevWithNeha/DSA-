#include<bits/stdc++.h>
using namespace std;
class maxheap{

    public:
    vector<int> heap;

   void insert(int val){
    heap.push_back(val);

    int i = heap.size()-1;

    while(i>0){
        int parent = (i-1)/2;

        if(heap[parent] < heap[i]){
            swap(heap[parent],heap[i]);
            i = parent;
        } else break;
    }
   }

   int deletemax(){
    if(heap.size() == 0) return -1;

    int maxval = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    int i = 0;
    int n = heap.size();

    while(2*i+1 < n){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;

        if(left < n && heap[left] > heap[largest]){
            largest = left;
        }

        if(right < n && heap[right] > heap[largest]){
            largest = right;
        }

        if(largest == i) break;

        swap(heap[i],heap[largest]);
        i = largest;
    }
    return maxval;
   }

   void print(){
    for(int x:heap){
        cout<<x<<" ";
    }
    cout<<endl;
   }
};

int main(){
    maxheap h;

    h.insert(50);
    h.insert(56);
    h.insert(100);
    h.insert(4);
    h.insert(20);

    h.print();

    cout<<"delete:"<<h.deletemax() << endl;

    h.print();

}