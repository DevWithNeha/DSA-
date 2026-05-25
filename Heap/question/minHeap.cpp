#include<bits/stdc++.h>
using namespace std;
class minheap{
    public:
    vector<int> heap;

void insert(int val){
    heap.push_back(val);

    int i = heap.size()-1;

    while(i>0){
        int parent = (i-1)/2;

        if(heap[parent] > heap[i]){
            swap(heap[parent],heap[i]);
            i = parent;
        } else break;
    }
}

int deleteheap(){
    if(heap.size() == 0) return -1;

    int minval = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    int i=0;
    int n = heap.size();

    while(2*i+1 < n){
        int left = 2*i+1;
        int right = 2*i+2;
        int smallest = i;

        if(left < n && heap[left] < heap[smallest]){
            smallest = left;
        }

        if(right < n && heap[right] < heap[smallest]){
            smallest = right;
        }

        if(smallest == i) break;

        swap(heap[i],heap[smallest]);
        i = smallest;
    }
    return minval;
}
void print(){
    for(int x:heap){
        cout<<x<<" ";
    }
    cout<<endl;
}

};

int main(){
    minheap h;

    h.insert(45);
    h.insert(20);
    h.insert(14);
    h.insert(12);
    h.insert(31);
    h.insert(7);
    h.insert(11);
    h.insert(13);
    h.insert(7);
    h.insert(6);
    h.insert(25);
    h.insert(18);

    h.print();

    cout<<"delete "<<h.deleteheap()<<endl;

    h.print();
}